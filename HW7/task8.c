#include <stdio.h>

int print_num(int numA, int numB);

int main(void)
{
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("%d\n", print_num(num1, num2));
    return 0;
}
int print_num(int numA, int numB)
{
    if ( numA > numB )
    {
        printf("%d ",numA);
        return print_num(numA - 1, numB);
    }
    else if ( numA < numB)
    {
        printf("%d ",numA);
        return print_num(numA + 1, numB);
    }
    return numB;
}
