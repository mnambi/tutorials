#include "udp_client.h"

#include <cstring>

#define PORT 1153

UdpClient::UdpClient()
{



}

void UdpClient::connect()
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

    memset((char *)&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(PORT);
    recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    std::cout << "Setup receive" << std::endl;

     if (bind(sock, (struct sockaddr *)&recv_addr, sizeof(recv_addr)) < 0)
     {
         std::cout << "Bind failed" << std::endl;
         return;
     }

}

void UdpClient::receive()
{
    socklen_t addr_len = sizeof(recv_addr);
    std::cout << "Receiving" << std::endl;
    while(1)
    {
        sleep(1000);
        char * msg = "Hello";
        std::cout << "Msg: " << msg << std::endl;

        int recvLen = recvfrom(sock, msg, 2048, 0, (struct sockaddr *)&recv_addr, &addr_len);
        if(recvLen < 0)
        {
            std::cout << "Receive failed." << std::endl;

        }
        else
        {
            std::cout << "Message received " << msg << std::endl;
        }

    }



}
