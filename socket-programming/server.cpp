#include<iostream>
#include<cstring>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>


int main(){
    int serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocketFd == -1){
        std::cerr<<" Server Socket creation failed"<<std::endl;
        return -1;
    }

    sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;  // meaning any network interface it will accept like ethernet, wifi, or loopback like self host.

    if(bind(serverSocketFd, (struct sockaddr*)(&serverAddress), sizeof(serverAddress)) == -1){
        std::cerr<<"Error in socket binding for server"<<std::endl;
        return -1;
    }

    listen(serverSocketFd, 5); //here 5 indicates the queue size to limit the no of connection requests.

    char buffer[1024] = {0};

    int clientSocket = accept(serverSocketFd, nullptr, nullptr);

    while(true){
        std::memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) -1, 0);
        buffer[bytesRead] ='\0';
        std::cout<<" Client : "<<buffer<<std::endl;
    }

    close(serverSocketFd);

    
}