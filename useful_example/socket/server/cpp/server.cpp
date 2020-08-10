#include "server.hpp"
/*
1. socket
2. bind
3. listen
4. accept
5. rece/send
6. close
*/
FakeServer::FakeServer(std::string ip_addr, int ip_port) {
  _IP_adr = ip_addr;
  _IP_port = ip_port;
  // socket的建立
  socket_init();
}

FakeServer::~FakeServer() {
  socket_quit();
}

int FakeServer::socket_init() {
  //socket info
  int addr_len = sizeof(client_Info);
  memset(&sever_info, 0, sizeof(sever_info));
  sever_info.sin_family = AF_INET;      // ivp4
  sever_info.sin_addr.s_addr = inet_addr(_IP_adr.c_str());
  sever_info.sin_port = htons(_IP_port);

  //socket
  socket_field = socket(AF_INET, SOCK_STREAM, 0);
  int error = 0;
  if (socket_field == -1) {
    std::cout<<"Fail to create a socket.\n";
  } else
    std::cout<<"Socket successfully created..\n";

  //bind
  error = bind(socket_field, (struct sockaddr *)&sever_info, sizeof(sever_info));
  if(!error){
    std::cout<<"Succeed to bind the port.\n";
  }else{
    std::cout<<"Fail to bind the port.\n";
  }
  return 0;
}

int FakeServer::socket_quit() {
  return close(socket_field);
}

int FakeServer::run_server(){
  int num_read = 0;
  int num_reconnect = 0;
  int error = 0;
  uint32_t input_data = 0x0;
  int count = 0;
  int addr_len = sizeof(client_Info);
  while (1) {
    std::cout<<"Waiting the "<<count<<"-th command...\n";
    //listen
    error = listen(socket_field, 5);
    if(!error){
      std::cout<<"Server listening...\n";
    }
    else{
      std::cout<<"Cannot listen...\n";
    }
    //accept
    client_socket = accept(socket_field, (struct sockaddr *)&client_Info,
                           (socklen_t *)&addr_len);
    if (client_socket > 0) {
      std::cout<<"Server acccept succeed:\n";
      do {
        num_read = recv(client_socket, &input_data, 4, 0);
        if (num_read > 0) {
          uint32_t send_back = 0xffffffff;

          printf("Get msg: %08x\n",input_data);
          printf("sned back: %08x\n",input_data);

          send(client_socket, &send_back, 4, 0);

        } else {
          std::cout<<"data: (1)end of command or (2)no input data.\n";
        }
      } while (num_read > 0); // end do loop
      close(client_socket);
      count++;
      num_reconnect = 0;
    } else {
      std::cout<<"Server acccept failed...\n";
      num_reconnect++;
      if(num_reconnect > 5)
        exit(0);
    }
  }
}