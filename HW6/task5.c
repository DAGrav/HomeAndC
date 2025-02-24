#include <stdio.h>
#include <inttypes.h>

unsigned long summ(uint16_t a);
int main(void)
{
    uint16_t numA;
    scanf("%hu", &numA);
    printf("%lu\n", summ(numA));
    return 0;
}

unsigned long summ(uint16_t a)
{
    return  a * (a + 1)/2;
}
