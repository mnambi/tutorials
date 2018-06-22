#include "udp_server.h"

#define PORT 1153

struct sockaddr_in broadcast_addr;
struct sockaddr_in recv_addr;

int sock;

UdpServer::UdpServer()
{



}

void UdpServer::connect()
{
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        std::cout << "Cannot create socket." << std::endl;
        return;
    }

    //int len = sizeof(struct sockaddr_in);
    char recvBuff[50];
    int recvBuffLen = 50;
    //char sendMsg[] = "broadcast message from salam rofl";

    std::cout << "Setting socket options" << std::endl;
    int enabled = true;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char*)&enabled, sizeof(enabled)) < 0)
    {
        std::cout << "Unable to set Socket options" << std::endl;
        return;
    }

    memset((char *)&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(PORT);
    broadcast_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    std::cout << "Setup broadcast" << std::endl;

    if(bind(sock, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr)) == -1)
    {
        std::cout << "Bind failed" << std::endl;
        return;

    }

}

void UdpServer::run()
{
    std::cout << "Broadcasting" << std::endl;
    while(1)
    {
        sleep(1000);
        char * msg = "Hello";
        std::cout << "Msg: " << msg << std::endl;

        if (sendto(sock, msg, strlen(msg)+1, 0, (sockaddr *)&broadcast_addr, sizeof(broadcast_addr)) < 0)
        {
            std::cout << "Broadcast failed." << std::endl;
        }
    }

}
