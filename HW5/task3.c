#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
    int8_t numA, numB;
    uint32_t summ = 0;
    scanf("%hhd%hhd", &numA, &numB);
    numA = abs(numA);
    numB = abs(numB);
    if (numA <= 100 && numB <= 100)
    {
        for (uint8_t i = numA; i <= numB; i++)
        {
           summ += i*i;
        }
        printf("%u\n", summ);
    }
    return 0;
}
