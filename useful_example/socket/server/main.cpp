#include "server.hpp"

int main(){
  std::cout<<" Socket example :\n";

  int ip_port = 3490;
  std::string ip_addr = "127.0.0.1";

  FakeServer server(ip_addr, ip_port);
  server.run_server();
  
  return 0;
}