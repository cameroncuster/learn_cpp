#include "trim.h"

void cTrim(char theString[], trimType method)
{
    int i = 0;
    char *tempStr = nullptr;
    if (method == FRONT || method == BOTH)
    {
        while(i < strlen(theString) && theString == 0)
        {
            strcpy(theString, &theString[i]);
            i++;
        }
    }
    
    if (method == END || method == BOTH)
    {
        // remove whitespace from end of string
    }
}

void sTrim(string &theString, trimType method)
{
    if (method == FRONT || method == BOTH)
    {
        // remove whitespace from beginning of string
    }
    else if (method == END || method == BOTH)
    {
        // remove whitespace from end of string
    }
}