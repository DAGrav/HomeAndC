
#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    scanf("%d%d%d", &num1, &num2, &num3);
    if ((num1 < num2) && (num2 < num3))
    {
        printf("%s\n", "YES");
    }
    else
    {
        printf("%s\n", "NO");
    }
    return 0;
}
