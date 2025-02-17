
#include <stdio.h>

int main(void)
{
    int num1, num2, num3, num4, minNum;
    scanf("%d%d%d%d%d", &num1, &num2, &num3, &num4, &minNum);
    minNum = (num1 < minNum) ? num1 : minNum;
    minNum = (num2 < minNum) ? num2 : minNum;
    minNum = (num3 < minNum) ? num3 : minNum;
    minNum = (num4 < minNum) ? num4 : minNum;
    printf("%d\n", minNum);
    return 0;
}
