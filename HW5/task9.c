
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num1;
    uint8_t flagNo = 0;
    scanf("%u", &num1);
    while (num1 > 0)
    {
        if (num1 % 2)
        {
            flagNo = 1;
            break;
        }
        num1 /=10;
    }
    printf("%s\n", flagNo > 0 ? "NO": "YES");
    return 0;
}
