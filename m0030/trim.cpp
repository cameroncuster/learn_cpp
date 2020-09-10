#define _CRT_SECURE_NO_WARNINGS
#include "trim.h" 

void cTrim(char theString[], trimType method)
{
    int i = 0;
    if (method == FRONT || method == BOTH)
    {
        while (isspace(theString[i]) != 0)
        {
            strcpy(theString, &theString[i]);
            i++;
        }
    }
    i = strlen(theString) - 1;
    if (method == END || method == BOTH)
    {
        while (i >= 0 && isspace(theString[i]))
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
        while (it != theString.end() && isspace(*it))
        {
            it++;
        }
    }
    it = theString.end() - 1;
    if (method == END || method == BOTH)
    {
        // remove whitespace from end of string
    }
}