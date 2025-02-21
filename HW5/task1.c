#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint8_t num1;
    scanf("%hhu", &num1);
    if (num1 <= 100)
    {
        for (uint8_t i = 1; i <= num1; i++)
        {
            printf("%d %d %d\n", i, i*i, i*i*i);
        }
    }
    return 0;
}

