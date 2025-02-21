
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    const uint8_t sample = 9;
    uint32_t num1;
    uint8_t countNum = 0;
    scanf("%u", &num1);
    while (num1 > 0)
    {
        if (sample == (num1 % 10))
        {
            countNum++;
        }
        num1 /=10;
    }
    printf("%s\n", countNum != 1 ? "NO": "YES");
    return 0;
}
