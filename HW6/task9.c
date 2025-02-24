#include <stdio.h>
#include <inttypes.h>

int factorial(int n);
int main(void)
{
    int num1;
    scanf("%d", &num1);
    printf ("%d\n",factorial(num1));
    return 0;
}

int factorial(int n)
{
    int result = 1;
    for(int i=2; i<=n; i++ )
    {
        result *=i;
    }
    return result;
}
