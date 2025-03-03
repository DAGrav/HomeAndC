#include <stdio.h>

int print_summ_num(int num);

int main(void)
{
    int num1;
    scanf("%d", &num1);
    printf("%d\n",print_summ_num(num1));
    return 0;
}
int print_summ_num(int num)
{
    if ( num > 1 )
    {
        num = print_summ_num(num - 1) + num ;
    }
    return num ;
}
