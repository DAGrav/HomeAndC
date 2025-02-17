
#include <stdio.h>

int main(void)
{
    int num1, num2, num3, num4, maxNum;
    scanf("%d%d%d%d%d", &num1, &num2, &num3, &num4, &maxNum);
    maxNum = (num1 > maxNum) ? num1 : maxNum;
    maxNum = (num2 > maxNum) ? num2 : maxNum;
    maxNum = (num3 > maxNum) ? num3 : maxNum;
    maxNum = (num4 > maxNum) ? num4 : maxNum;
    printf("%d\n", maxNum);
    return 0;
}
