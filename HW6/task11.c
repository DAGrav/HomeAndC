
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int nod(int a, int b);
int main(void)
{
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("%d\n", (num1 > num2) ? nod(num1, num2): nod(num2, num1) ) ;
    return 0;
}

int nod(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return nod(b,(a % b));
    }
}
