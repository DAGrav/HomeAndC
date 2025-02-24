#include <stdio.h>
#include <inttypes.h>

void print_simple(int n);
int main(void)
{
    int num1;
    scanf("%d", &num1);
    print_simple(num1);
    return 0;
}

void print_simple(int n)
{
    for(int i=2; i<=n/2; )
     {
        if (n%i==0)
        {
            printf("%d ", i);
            n /= i;
        }
        else i++;
    }
    printf("%d\n", n);
}
