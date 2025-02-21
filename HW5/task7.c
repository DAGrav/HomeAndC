
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num1, testNum;
    uint8_t preNum = 0, countNum = 0;
    scanf("%u", &num1);
    while (num1 > 0)
    {
        preNum = num1 % 10;
        num1 /=10;
        testNum = num1;
        while (testNum > 0)
        {
            if (preNum == (testNum % 10))
            {
                countNum++;
                num1 = 0;
                break;
            }
            testNum /=10;
        }
    }
    printf("%s\n", countNum > 0 ? "YES": "NO");
    return 0;
}
