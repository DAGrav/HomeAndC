#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
int main(void)
{
    uint32_t number = 0, mask = 1;
    uint8_t count = 0;
    scanf( "%du", &number );
    for (int i = 0; i < 32; i++)
    {
        if (number & mask)
            count++;
        mask <<= 1;
    }
    printf("%d\n", count);
    return 0;
}
