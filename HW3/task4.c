
#include <stdio.h>

int main(void)
{
    unsigned short num1, num2, num3;
    scanf("%1hu%1hu%1hu", &num1, &num2, &num3);
    printf("%u", (num1 + num2 + num3));
    return 0;
}
