#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num1;
    uint8_t prevNum, flagNo = 0;
    scanf("%u", &num1);
    prevNum = (num1 % 10);
    while (num1 > 0)
    {
        num1 /=10;
        if (prevNum > (num1 % 10) )
        {
            prevNum = num1 % 10;
        }
        else
        {
            flagNo = 1;
            break;
        }
    }
    printf("%s\n", flagNo > 0 ? "NO": "YES");
    return 0;
}
