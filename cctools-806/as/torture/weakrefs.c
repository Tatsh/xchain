#include <stdio.h>

extern int wibble() __attribute__ ((weak_import));

int main()
{
    wibble();
    return 0;
} 

