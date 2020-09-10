#define _CRT_SECURE_NO_WARNINGS
#include "trim.h" 

void cTrim(char theString[], trimType method)
{
    int i = 0;
    if (method == FRONT || method == BOTH)
    {
        while (i >= 0 && isspace(theString[i]) != 0)
        {
            strcpy(theString, &theString[i]);
            i++;
        }
    }
    i = strlen(theString) - 1;
    if (method == END || method == BOTH)
    {
        while (i >= 0 && isspace(theString[i]) != 0)
        {
            i--;
        }
        i++;
        theString[i] = '\0';
    }
}

void sTrim(string &theString, trimType method)
{
    string::iterator it;
    if (method == FRONT || method == BOTH)
    {
        it = theString.begin();
        while (it != theString.end() && isspace(*it) != 0)
        {
            *it++;
        }
        theString.erase(theString.begin(), it);
    }
    it = theString.end() - 1;
    if (method == END || method == BOTH)
    {
        while (*it >= 0 && isspace(*it) != 0)
        {
            *it--;
        }
        *it++;
        theString.erase(it, theString.end());
    }
}