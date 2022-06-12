#include "../inc/main.h"

bool GetUserFormattedInput(char * output, char * format, int numFields, ...)
{
    char str[256] = {0};
    va_list argPtr;
    va_start(argPtr, numFields);

    printf(output);

    if (fgets(str, ARRAY_SIZE(str), stdin) != NULL)
    {
        if (vsscanf(str, format, argPtr) == numFields)
        {
            va_end(argPtr);
            return true;
        }
    }

    va_end(argPtr);
    return false;
}

void ClearScreen(void)
{
    system("clear");
}