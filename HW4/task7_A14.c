
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint8_t num1, num2, maxNum;
    scanf("%1hhu%1hhu%1hhu", &num1, &num2, &maxNum);
    maxNum = (num1 > maxNum) ? num1 : maxNum;
    maxNum = (num2 > maxNum) ? num2 : maxNum;
    printf("%hhu\n", maxNum);
    return 0;
}
