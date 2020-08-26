#include "network.h"

ip compressOctets(octet octet0, octet octet1, octet octet2, octet octet3) {
    ip ipAddress = octet0;
    ipAddress = ipAddress << 8;
    ipAddress = ipAddress | octet1;
    ipAddress = ipAddress << 8;
    ipAddress = ipAddress | octet2;
    ipAddress = ipAddress << 8;
    ipAddress = ipAddress | octet3;

    return ipAddress;
}

void extractOctets(ip ipAddress, octet &octet0, octet &octet1, octet &octet2, octet &octet3) {
    octet3 = ipAddress & 255;
    ipAddress = ipAddress >> 8;
    octet2 = ipAddress & 255;
    ipAddress = ipAddress >> 8;
    octet1 = ipAddress & 255;
    ipAddress = ipAddress >> 8;
    octet0 = ipAddress & 255;

}