
#include <stdio.h>

int main(void)
{
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    if (num1 == num2)
    {
        printf("%s\n", "Equal");
    }
    else
    {
        printf("%s\n", (num1 > num2) ? "Above" : "Less");
    }
    return 0;
}
