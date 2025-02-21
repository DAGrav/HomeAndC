#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
    int8_t numA, numB;
    scanf("%hhd%hhd", &numA, &numB);
    numA = abs(numA);
    numB = abs(numB);
    if (numA <= 100 && numB <= 100)
    {
        for (uint8_t i = numA; i <= numB; i++)
        {
            printf("%d ", i*i);
        }
        printf("\n");
    }
    return 0;
}

