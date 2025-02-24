#include <stdio.h>
#include <inttypes.h>
#include <math.h>

unsigned long long machFx(uint8_t numCell);
int main(void)
{
    uint8_t numCell;
    scanf("%hhu", &numCell);
    printf("%llu\n", machFx(numCell));
    return 0;
}

unsigned long long machFx(uint8_t numCell)
{
    return pow(2, numCell-1);
}
