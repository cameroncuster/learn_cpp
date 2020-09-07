#include "trim.h"

void cTrim(char &strManip, trimType method)
{
    char tempStr = NULL;
    if (method == FRONT)
    {
        for (int i = 0; i <= strlen(&strManip); i++)
        {
            if (strManip[i].isspace() == false)
            {
                tempStr = strcpy(tempStr, &strManip);
            }
        }
    }
    else if (method == END)
    {
        // remove whitespace from end of string
    }
    else if (method == BOTH)
    {
        // remove whitespace from beginning and end of string
    }
}

void sTrim(string &stringManip, trimType method)
{
    if (method == FRONT)
    {
        // remove whitespace from beginning of string
    }
    else if (method == END)
    {
        // remove whitespace from end of string
    }
    else if (method == BOTH)
    {
        // remove whitespace from beginning and end of string
    }
}