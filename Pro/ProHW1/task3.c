#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
int main(void)
{
    uint32_t number = 0, mask = 0xFFFFFFFF;
    uint8_t index = 0;
    scanf( "%du", &number );
    scanf( "%hhu", &index );
    if ((index > 0) && (index >> 5 == 0))
    {
    mask >>= (32 - index);
    printf("%d\n", number & mask);
    }
    return 0;
}

