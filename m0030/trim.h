#include <cctype>
#include <cstring>
#include <string>

using namespace std;

enum trimType{BOTH, FRONT, END};

void cTrim(char, trimType);

void sTrim(std::string, trimType);