#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

int main(){
    int clientSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocketFd == -1){
        std::cerr<<"Error in creating client socket"<<std::endl;
        return -1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr =  INADDR_ANY; // or we can give inet_addr("127.0.0.1") for now we are using wildcard address meaning we are connecting/listening to all interface.

    if (connect(clientSocketFd, (struct sockaddr*)(&serverAddress), sizeof(serverAddress)) <0){
        std::cerr<<"Error in connecting to server"<<std::endl;
        close(clientSocketFd);
        return -1;
    }

    std::string message;
    
    while(true){
        std::cin>>message;
        if(send(clientSocketFd, message.c_str(), message.length(), 0) < 0){
            std::cerr<<"Message sending is failed - try sending again"<<std::endl;
            continue;
        }
    }
    
    close(clientSocketFd);

    return 0;
}