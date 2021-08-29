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

networkType getNetworkType(ip ipAddress) {
    octet octet3 = ipAddress & 255;
    ipAddress = ipAddress >> 8;
    octet octet2 = ipAddress & 255;
    ipAddress = ipAddress >> 8;
    octet octet1 = ipAddress & 255;
    ipAddress = ipAddress >> 8;
    octet octet0 = ipAddress & 255;

    if (octet0 == 0) {
        return INVALID;
    }
    else if (octet0 < 127 && octet0 >= 1) {
        if (octet0 == 10) {
            return APRIVATE;
        }
        return CLASSA;
    }
    else if (octet0 == 127) {
        return LOCALHOST;
    }
    else if (octet0 >= 128 && octet0 <= 191) {
        if (octet0 == 172 && octet1 >= 16 && octet1 <= 31) {
            return BPRIVATE;
        }
        return CLASSB;
    }
    else if (octet0 >= 192 && octet0 <= 223) {
        if (octet0 == 192 && octet1 == 168) {
            return CPRIVATE;
        }
        return CLASSC;
    }
    else if (octet0 >= 224 && octet0 <= 239) {
        return CLASSD;
    }
    else if (octet0 >= 240 && octet0 <= 255) {
        return CLASSE; 
    }
    return INVALID;
}