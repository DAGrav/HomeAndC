
#include <stdio.h>

int main(void)
{
    int num1, num2, maxNum;
    scanf("%d%d%d", &num1, &num2, &maxNum);
    maxNum = (num1 > maxNum) ? num1 : maxNum;
    maxNum = (num2 > maxNum) ? num2 : maxNum;
    printf("%d\n", maxNum);
    return 0;
}
