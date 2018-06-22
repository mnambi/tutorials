#ifndef UDP_SERVER_H_
#define UDP_SERVER_H_

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

class UdpServer
{
public:
    UdpServer();

    void connect();
    void run();

protected:


};

#endif // UDP_SERVER_H_
