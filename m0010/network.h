#ifndef __NETWORK__H__
#define __NETWORK__H__

// Enumerated type starting at 0
enum networkType { INVALID, CLASSA, APRIVATE, LOCALHOST, CLASSB, BPRIVATE, CLASSC, CPRIVATE, CLASSD, CLASSE };

// Two typedef's created for short int and unsigned int
typedef unsigned short int octet;
typedef unsigned int ip;

// Three function prototypes
ip compressOctets(octet, octet, octet, octet);
void extractOctets(ip, octet &, octet &, octet &, octet &);

#endif