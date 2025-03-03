#include <stdio.h>

void print_num(int num);

int main(void)
{
    int num1;
    scanf("%d", &num1);
    if (num1 > 0)
        print_num(num1);
    else
        printf("%d\n",num1);
    printf("\n");
    return 0;
}
void print_num(int num)
{

    if ( num > 0 )
    {
        printf("%d ", num % 10);
        print_num(num / 10) ;
    }
    return;
}
