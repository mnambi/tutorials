#include "udp_server.h"

#include <iostream>


/**
* @file main.cpp 
* @author mnambi
*/

int main(int argc, char** argv)
{
    UdpServer udpServer;
    udpServer.connect();
    udpServer.run();


    return 0;
}
