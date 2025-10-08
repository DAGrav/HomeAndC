#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
int main(void)
{
    uint32_t number = 0, mask,max = 0,temp = 0;
    uint8_t index = 0;
    scanf( "%du", &number );
    scanf( "%hhu", &index );
    if ((index > 0) && (index >> 5 == 0))
    {
        mask = ( 1 << index ) - 1;
        for (int i = 0; i < 33 - index; i++)
        {
            temp = (number >> i) & mask;
            if (temp > max)
                max = temp;
        }
        printf("%d\n",  max);
    }
    return 0;
}
