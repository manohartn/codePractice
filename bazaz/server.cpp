#include <iostream>
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

using namespace std;

//////server is client!!! wrong naming aste


int main ()
{
    int udp_clientSock = 0;
    socklen_t len_udp =0, len_saddr_udp = 0;
    struct in_addr **udp_addr_list;
    char *buf1 = (char *)malloc(sizeof(char*)*25);
    struct sockaddr_in udp_serv_addr, udp_client_addr;
    if ((udp_clientSock= socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        perror("socket() failed");

    udp_serv_addr.sin_family= AF_INET; /* Internet address family */

    bzero((char *) &udp_serv_addr, sizeof(udp_serv_addr));
    memset(&udp_client_addr,0,sizeof(udp_client_addr));

    struct hostent *udp_ip_id;

    udp_ip_id=gethostbyname("localhost");
    if(udp_ip_id == NULL)
    {
        perror("gethostbyname error");
        exit(-1);
    }
    udp_addr_list = (struct in_addr **)udp_ip_id->h_addr_list;
    bcopy((char*)udp_ip_id->h_addr, (char *)&udp_serv_addr.sin_addr.s_addr, udp_ip_id->h_length);

    udp_serv_addr.sin_family = AF_INET;
    //udp_serv_addr.sin_addr.s_addr= INADDR_ANY;
    udp_serv_addr.sin_port = htons(5000);
    bzero(&udp_serv_addr.sin_zero, 8);

    udp_client_addr.sin_addr.s_addr= INADDR_ANY;
    udp_client_addr.sin_family= AF_INET;
    bcopy((char*)udp_ip_id->h_addr, (char *)&udp_client_addr.sin_addr.s_addr, udp_ip_id->h_length);

    if (bind(udp_clientSock, (struct sockaddr *) &udp_client_addr, sizeof(udp_client_addr)) < 0)
        perror("bind() failed");


    len_saddr_udp = sizeof(struct sockaddr);
    memset(&udp_client_addr,0,sizeof(udp_client_addr));
    if((getsockname(udp_clientSock,(struct sockaddr*)&udp_client_addr,&len_saddr_udp)) < 0)
    {
        perror("getsockname error");
        exit(-1);
    }

    std::cout << "Dynamic UDP port number" << ntohs(udp_client_addr.sin_port) << "and IP address %s.\n"<< inet_ntoa(udp_client_addr.sin_addr);
    
    cout<<"sending with port number" << ntohs(udp_client_addr.sin_port);

    len_udp = sizeof(udp_serv_addr);

    strcpy(buf1, "12");

    if(sendto(udp_clientSock, buf1, 25, 0, (struct sockaddr *)&udp_serv_addr, len_udp)<0)
    {
        perror("sending err");
    }


    std::cout<< "sent" << buf1 << "and IP address\n"  << inet_ntoa(udp_serv_addr.sin_addr);

	bzero(buf1, 25);
		if((recvfrom(udp_clientSock, buf1, 25, 0, (struct sockaddr*)&udp_serv_addr, &len_udp)) < 0)
		{
			perror("recv fail");
		}

		cout<<"recx with port number" << ntohs(udp_serv_addr.sin_port) << "and data \n"<< buf1;
		fflush(stdout);


    return 0;
}
