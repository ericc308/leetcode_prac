#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <unistd.h>
#include <vector>
#include <string.h>
#include <string>

#include <sys/types.h>
#include <arpa/inet.h> //inet_addr
#include <netinet/in.h>
#include <sys/socket.h>

class FakeServer {

  int socket_field = 0, client_socket = 0;
  struct sockaddr_in sever_info, client_Info;

  std::string _IP_adr;
  int _IP_port;

public:
  FakeServer() = delete;
  FakeServer(std::string ip_addr, int ip_port);
  ~FakeServer();
  int run_server();
  int socket_init();
  int socket_quit();

};