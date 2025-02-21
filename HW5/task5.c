#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num1, summ = 0;
    scanf("%u", &num1);
    while (num1 > 0)
    {
       summ += num1 % 10;
       num1 /=10;
    }
    printf("%u\n", summ);
    return 0;
}
