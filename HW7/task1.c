#include <stdio.h>

void print_num(int num);

int main(void)
{
    int num1;
    scanf("%d", &num1);
    print_num(num1);
    printf("\n");
    return 0;
}
void print_num(int num)
{
    if ( num > 1 )
    {
        print_num(num - 1)   ;
    }
    printf("%d ",num);
    return;
}

