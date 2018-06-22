#include "udp_client.h"

#include <iostream>


/**
* @file main.cpp 
* @author mnambi
*/

int main(int argc, char** argv)
{
    UdpClient udpClient;
    udpClient.connect();
    udpClient.receive();


    return 0;
}
