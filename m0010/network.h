#ifndef __NETWORK__H__
#define __NETWORK__H__

// Enumerated type starting at 0
enum networkType { INVALID, CLASSA, APRIVATE, LOCALHOST, CLASSB, BPRIVATE, CLASSC, CPRIVATE, CLASSD, CLASSE };

// Two typedef's created for short int and unsigned int
typedef unsigned short int octet;
typedef unsigned int ip;

// Three functions
ip compressOctets(octet octet0, octet octet1, octet octet2, octet octet3) {
    // form valid internet protocol address below
    
}

#endif