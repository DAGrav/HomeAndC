#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num1;
    uint8_t summ = 0;
    scanf("%u", &num1);
    while (num1 > 0)
    {
        num1 /=10;
        summ++;
    }
    printf("%s\n", summ == 3 ? "YES": "NO");
    return 0;
}
