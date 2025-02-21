#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num1;
    uint8_t prevNum = 0, flagYes = 0;
    scanf("%u", &num1);
    while (num1 > 0)
    {
        if (prevNum == (num1 % 10) )
        {
            flagYes = 1;
            break;
        }
        else
        {
            prevNum = num1 % 10;
        }
       num1 /=10;
    }
    printf("%s\n", flagYes > 0 ? "YES": "NO");
    return 0;
}
