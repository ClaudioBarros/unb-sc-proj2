#include "aes.h" 
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "tests.h"

void printBytesHex(u8* bytes, uint numBytes)
{
    printf("[");
    for(int i = 0; i < numBytes; i++)
    {
        if((i+1) % 8 == 0 && i > 0)
            printf(" 0x%x \n ", *bytes++);
        else
            printf(" 0x%x ", *bytes++);
    }
    printf("]\n");
}

void printBytesDecimal(u8* bytes, uint numBytes)
{
    printf("[");
    for(int i = 0; i < numBytes; i++)
    {
        if(i == 8)
            printf(" %u \n ", *bytes++);
        else
            printf(" %u ", *bytes++);
    }
    printf("]\n");
}

int main()
{
    runAllTests();
}
