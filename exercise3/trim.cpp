#define _CRT_SECURE_NO_WARNINGS
#include "trim.h" 

void cTrim(char theString[], trimType method)
{
    int i = 0;
    if (method == FRONT || method == BOTH)
    {
        while (i <= strlen(theString) && isspace(theString[i]) != 0)
        {
            i++;
        }
        strcpy(theString, &theString[i]);
    }
    i = int(strlen(theString) - 1);
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
            it++;
        }
        theString.erase(theString.begin(), it);
    }
    if (method == END || method == BOTH)
    {
        if (theString.size() == 0)
        {
            return;
        }
        it = theString.end() - 1;
        while (it != theString.begin() && isspace(*it) != 0)
        {
            it--;
        }
        if (it == theString.begin())
        {
            theString.erase(it, theString.end());
        }
        else
        {
            it++;
            theString.erase(it, theString.end());
        }
    }
}