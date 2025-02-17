
#include <stdio.h>

int main(void)
{
    int num1, num2, num3, num4, minNum, maxNum = 0;
    scanf("%d%d%d%d%d", &num1, &num2, &num3, &num4, &minNum);
    //Search max
    maxNum = (minNum > maxNum) ? minNum : maxNum;
    maxNum = (num1 > maxNum) ? num1 : maxNum;
    maxNum = (num2 > maxNum) ? num2 : maxNum;
    maxNum = (num3 > maxNum) ? num3 : maxNum;
    maxNum = (num4 > maxNum) ? num4 : maxNum;
    // Search min
    minNum = (num1 < minNum) ? num1 : minNum;
    minNum = (num2 < minNum) ? num2 : minNum;
    minNum = (num3 < minNum) ? num3 : minNum;
    minNum = (num4 < minNum) ? num4 : minNum;
    printf("%d\n", minNum + maxNum);
    return 0;
}

