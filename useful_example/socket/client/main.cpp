#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h> //inet_addr
#include <netinet/in.h>
#include <sys/socket.h>
#define SD_SEND SHUT_WR
#endif

/*
1. socket
2. connect
3. rece/send
4. close
*/

int sockInit(void) {
#ifdef _WIN32
  WSADATA wsa_data;
  return WSAStartup(MAKEWORD(1, 1), &wsa_data);
#else
  return 0;
#endif
}
int sockQuit(void) {
#ifdef _WIN32
  return WSACleanup();
#else
  return 0;
#endif
}

int main(){
  std::cout<<"Socket example client :\n";

  int ip_port = 3490;
  std::string ip_addr = "127.0.0.1";

#ifdef _WIN32
  sockInit();
  SOCKET sockfd;
#else
  int sockfd = 0;
#endif

  // create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    printf("Fail to create a socket.\n");
  }

  // socket的連線
  struct sockaddr_in info;
  memset(&info, 0, sizeof(info));
  info.sin_family = PF_INET;
  info.sin_addr.s_addr = inet_addr(ip_addr.c_str());
  info.sin_port = htons(ip_port);

  int err = connect(sockfd, (struct sockaddr *)&info, sizeof(info));
  if (err == -1) {
    printf("Connection error\n");
  }

  // send msg to client
  uint32_t send_msg[4] = {0x12000000, 0x00340000, 0x00005600, 0x00000078};

  send(sockfd, &send_msg[0], 4, 0);
  send(sockfd, &send_msg[1], 4, 0);
  send(sockfd, &send_msg[2], 4, 0);
  send(sockfd, &send_msg[3], 4, 0);

  shutdown(sockfd, SD_SEND);

  // rece msg from server
  int numRead = 0;
  int iby = 1;
  uint32_t receiveMessage = 0x0;

  printf("Waiting reponse ...\n");
  do {
    printf("Reading the %dnd byte \n", iby);
    numRead = recv(sockfd, &receiveMessage, 4, 0);
    if (numRead > 0) {
      printf("Receive %d bytes data...\n", numRead);
      printf("%08x ", receiveMessage);
      printf("\n");
    } else {
      printf("No data : %d\n", numRead);
    }
    iby++;
  } while (numRead > 0);

  printf("Closed Socket\n");

#ifdef _WIN32
  closesocket(sockfd);
#else
  close(sockfd);
#endif
  sockQuit();

}