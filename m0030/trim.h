#include <cctype>
#include <cstring>
#include <string>

using namespace std;

enum trimType{BOTH, FRONT, END};

void cTrim(char theString[], trimType method);
void sTrim(string& theString, trimType method);