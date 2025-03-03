#include <stdio.h>

int print_num(int num);

int main(void)
{
    int num1;
    scanf("%d", &num1);
    printf("%d\n", print_num(num1));
    return 0;
}
int print_num(int num)
{
    if ( num <= 1 )
    {
        return 1;
    }
    printf("%d ",num);
    return print_num(num - 1)   ;
}
