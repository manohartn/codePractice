#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <signal.h>
#include <iostream>
#include <thread>
#include <mutex>

#include <queue>
using namespace std;

std::mutex thread_mutex;


int map [260][4];



class gl_struct{
public:
	struct my_data{
		char source[25];
		char dest[25];
		int no_of_bytes;
		int port_no;
		int vlan_id;
	}data;
	struct sockaddr_in cli;
};

std::queue<gl_struct*> myQueue;

struct sockaddr_in server,client,send_cli;
struct hostent *ip_data;
struct in_addr **addr_list_udp;
int arb_sock = 0,yes=1;
socklen_t udp_clientlen=0;
char *buf = (char *)malloc(sizeof(char*)*25);
char *bufin2 = (char *)malloc(sizeof(char*)*25);
socklen_t len =0;


int get_min(int vlan_ind)
{
    int i, min, index;
    min = map [vlan_ind] [1];
    index = 1;
    for (i=2;i<=4;i++)
    {
        if (min > map[vlan_ind][i])
        {
            min = map[vlan_ind][i];
            index = i;
        }
    }
    map[vlan_ind][index] = map[vlan_ind][index] + 1;
    return (vlan_ind*10)+index;

}

int thread_method()
{

	cout<<"I reached venki"<<endl;


		//create socket
		if((arb_sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
		{
			perror("socket creation failure\n");
			exit(-1);
		}

		bzero((char *) &server, sizeof(server));
		//udp socket creation

		//        ip_data=gethostbyname("localhost");      //gets the host name
		//        addr_list_udp = (struct in_addr **)ip_data->h_addr_list;

		server.sin_family = AF_INET;
		server.sin_addr.s_addr= inet_addr("127.0.0.1");//INADDR_ANY;
		server.sin_port = htons(5000);
		bzero(&server.sin_zero, 8);

		//        bcopy((char*)ip_data->h_addr, (char *)&server.sin_addr.s_addr, ip_data->h_length);

		cout<<"Static UDP port"<<ntohs(server.sin_port)<<" and IP address\n "<< inet_ntoa(server.sin_addr);
		fflush(stdout);

		/*    if (setsockopt(arb_sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1)
          {
            perror("setsockopt");
        }
		 */

		/*bind socket*/
		if (bind(arb_sock, (struct sockaddr *) &server, sizeof(server)) < 0)
			perror("bind() failed");

		udp_clientlen = sizeof(client);
		cout<<"reached Kunchtiga"<<endl;
	while(1)
	{

		bzero(buf, 25);
		if((recvfrom(arb_sock, buf, 25, 0, (struct sockaddr*)&client, &udp_clientlen)) < 0)
		{
			perror("recv fail");
		}

		cout<<"recx with port number" << ntohs(client.sin_port) << "and data \n"<< buf;
		fflush(stdout);

		//adding logic EPIC

		/*	client.sin_family = AF_INET;
	client.sin_addr.s_addr= inet_addr("127.0.0.1");//INADDR_ANY;
	client.sin_port = htons(8000);
	bzero(&client.sin_zero, 8);*/



		int i=0,n = 2;

		//	for (i = 0; i <= 2; i++){
		gl_struct *d1 = new gl_struct();
		char jat[25]="donkey";
//		strcat(jat,itoa(i));
//		i++;
		strcpy(d1->data.source, "Hathi");
		d1->data.vlan_id=  atoi(buf);
		//strcpy(d1->source,"venki");
		strcpy(d1->data.dest,"rctfftr");
		d1->data.no_of_bytes = 10;
		d1->data.port_no = 5001;
		//		d1->cli.sin_family = AF_INET;
		//		d1->cli.sin_port = 7890;
		memcpy((struct sockaddr*)&d1->cli,(struct sockaddr*)&client, sizeof(struct sockaddr));
		memset(&client,0,sizeof(struct sockaddr_in));
		thread_mutex.lock();
		myQueue.push(d1);
		thread_mutex.unlock();

		cout<<"Size of queue is "<<myQueue.size()<<endl;
		cout<<"Port no is"<<myQueue.front()->cli.sin_port<<endl;
		cout<<"Socket Family is"<<myQueue.front()->cli.sin_family<<endl;


	}

	//        }


	return 0;
}


int thread_method2(){
	cout<<"AA gaya main thread 2 main"<<endl;
	while(1){
//		cout<<"I reached thread 2"<<endl;
		thread_mutex.lock();
		while(myQueue.size()>1){
			cout<<"Size of queue is "<<myQueue.size()<<endl;
			cout<<"front of the queue is "<<myQueue.front()->data.source<<endl;
//			send_cli
			memset(&send_cli,0,sizeof(struct sockaddr_in));
			memcpy((struct sockaddr*)&send_cli,(struct sockaddr*)&myQueue.front()->cli, sizeof(struct sockaddr));
			cout<<"value of the port and socket_family is "<<send_cli.sin_port<<send_cli.sin_family<<endl;
			strcpy(bufin2, "Asshole I work");

		    len= sizeof(send_cli);

		    cout << "Dynamic UDP port number" << ntohs(send_cli.sin_port) << endl<<"and IP address "<< inet_ntoa(send_cli.sin_addr);
		    cout<<"VLAN ID to be used is "<< get_min(myQueue.front()->data.vlan_id)<<endl;
  			  cout<<"sending with port number" << ntohs(send_cli.sin_port);
		    if(sendto(arb_sock, bufin2, 25, 0, (struct sockaddr *)&send_cli, len)<0)
		    {
		        perror("sending err");
		    }
			myQueue.pop();
		}
		thread_mutex.unlock();
	}

}



int main()
{

	//initialize the map
	int l,j;
	   for (l=0; l < 260; l++)
	   {
	      for(j=0; j <= 4; j++)
	         map[l][j] = 0;

	   }

	std::thread th(thread_method);
	std::thread th2(thread_method2);
	th.join();
	th2.join();
	cout << "hello" << endl;


	/*	for (i = 0; i <= 5; i++){

		cout<<"elements of the gl_struct queue are "<<myQueue.front()->data.source<<endl;
		myQueue.pop();
	}*/


	return 0;

}



