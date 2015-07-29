#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/ether.h>


#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define MY_DEST_MAC0    0xFF
#define MY_DEST_MAC1    0xFF
#define MY_DEST_MAC2    0xFF
#define MY_DEST_MAC3    0xFF
#define MY_DEST_MAC4    0xFF
#define MY_DEST_MAC5    0xFF
 
#define DEFAULT_IF  "wlan0"
#define BUF_SIZ     1024
 
int main(int argc, char *argv[])
{
    int sockfd;
    int ttl = 255;
    struct ifreq if_idx;
    struct ifreq if_mac;
    int tx_len = 0;
    char sendbuf[BUF_SIZ];
    struct ethhdr *eth_header;
    struct ether_header *eh = (struct ether_header *) sendbuf;
    struct sockaddr_ll socket_address;
    char ifName[IFNAMSIZ];
    unsigned short int vid = htons(12), vlanproto=htons(ETH_P_IP); 

    /* Get interface name */
    if (argc > 1)
        strcpy(ifName, argv[1]);
    else
        strcpy(ifName, DEFAULT_IF);
 
    /* Open RAW socket to send on */
    //if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
    if ((sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) {
    //if ((sockfd = socket(AF_INET, SOCK_RAW, ETH_P_ALL)) == -1) {
        perror("socket creation failure");
    }
    printf("size of ether header = %d\n", (int)sizeof(struct ether_header));
    printf("%x %x\n", ETH_P_ALL, ETH_P_IP);

    struct ifreq if_ip;
    memset(&if_ip, 0, sizeof(struct ifreq));
    strncpy(if_ip.ifr_name, "wlan0", IFNAMSIZ-1);
    if (ioctl(sockfd, SIOCGIFADDR, &if_ip) < 0)
        perror("SIOCGIFADDR");
 
    /* Get the index of the interface to send on */
    memset(&if_idx, 0, sizeof(struct ifreq));
    strncpy(if_idx.ifr_name, ifName, IFNAMSIZ-1);
    if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) < 0)
        perror("SIOCGIFINDEX");
    /* Get the MAC address of the interface to send on */
    memset(&if_mac, 0, sizeof(struct ifreq));
    strncpy(if_mac.ifr_name, ifName, IFNAMSIZ-1);
    if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) < 0)
        perror("SIOCGIFHWADDR");
 
    /* Construct the Ethernet header */
    memset(sendbuf, 0, BUF_SIZ);
    /* Ethernet header */
    eh->ether_shost[0] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[0];
    eh->ether_shost[1] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[1];
    eh->ether_shost[2] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[2];
    eh->ether_shost[3] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[3];
    eh->ether_shost[4] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[4];
    eh->ether_shost[5] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[5];
    eh->ether_dhost[0] = MY_DEST_MAC0;
    eh->ether_dhost[1] = MY_DEST_MAC1;
    eh->ether_dhost[2] = MY_DEST_MAC2;
    eh->ether_dhost[3] = MY_DEST_MAC3;
    eh->ether_dhost[4] = MY_DEST_MAC4;
    eh->ether_dhost[5] = MY_DEST_MAC5;
    /* Ethertype field */
    //eh->ether_type = htons(ETH_P_IP);
    eh->ether_type = htons(0x8100);
    tx_len += sizeof(struct ether_header);
    memcpy((void *)(sendbuf + tx_len), (void *) &vid, 2); 
    tx_len += 2;
    memcpy((void *)(sendbuf + tx_len), (void *) &vlanproto, 2);
    tx_len += 2; 

struct iphdr *iph = (struct iphdr *) (sendbuf + sizeof(struct ether_header) + 4);
/* IP Header */
iph->ihl = 5;
iph->version = 4;
iph->tos = 0; // Low delay
iph->id = htons(54321);
iph->ttl = ttl; // hops
iph->protocol = IPPROTO_UDP; // UDP
/* Source IP address, can be spoofed */
//iph->saddr = inet_addr(inet_ntoa(((struct sockaddr_in *)&if_ip.ifr_addr)->sin_addr));
iph->saddr = inet_addr("127.0.0.1");
// iph->saddr = inet_addr("192.168.0.112");
/* Destination IP address */
iph->daddr = inet_addr("127.0.0.1");
tx_len += sizeof(struct iphdr);

struct udphdr *udph = (struct udphdr *) (sendbuf + sizeof(struct iphdr) + sizeof(struct ether_header) + 4);
/* UDP Header */
udph->source = htons(6666);
udph->dest = htons(5342);
udph->check = 0; // skip
//udph->len = htons(8 + strlen(data));
udph->len = htons(13); //should be greater than 8 (update as per the length)
tx_len += sizeof(struct udphdr);

    /* Packet data */
    sendbuf[tx_len++] = 'h';//0xde;
    sendbuf[tx_len++] = 'e';//0xad;
    sendbuf[tx_len++] = 'l';//0xbe;
    sendbuf[tx_len++] = 'l';//0xef;
    sendbuf[tx_len++] = 'o';//0xef;
 
    /* Index of the network device */
    socket_address.sll_ifindex = if_idx.ifr_ifindex;
    socket_address.sll_family = AF_PACKET;
    //socket_address.sll_protocol = htons(ETH_P_IP); 
    socket_address.sll_protocol = htons(ETH_P_ALL); 
    //socket_address.sll_hatype = ARPHRD_ETHER;
    //socket_address.sll_pkttype = PACKET_OTHERHOST; 
    //socket_address.sll_halen = ETH_ALEN; 
    /* Address length*/
    socket_address.sll_halen = ETH_ALEN;
    /* Destination MAC */
    socket_address.sll_addr[0] = MY_DEST_MAC0;
    socket_address.sll_addr[1] = MY_DEST_MAC1;
    socket_address.sll_addr[2] = MY_DEST_MAC2;
    socket_address.sll_addr[3] = MY_DEST_MAC3;
    socket_address.sll_addr[4] = MY_DEST_MAC4;
    socket_address.sll_addr[5] = MY_DEST_MAC5;
 
    /* Send packet */
    if (sendto(sockfd, sendbuf, tx_len, 0, (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll)) < 0)
        printf("Send failed\n");
 
    return 0;
}
