#ifndef UDP_CLIENT_H_
#define UDP_CLIENT_H_

#include <iostream>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>


class UdpClient
{
public:
    UdpClient();

    void connect();
    void receive();

protected:
    struct sockaddr_in broadcast_addr;
    struct sockaddr_in recv_addr;

    int sock;

};

#endif //UDP_CLIENT_H_
