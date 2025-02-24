#include <stdio.h>
#include <inttypes.h>

int middle(int a, int b);
int main(void)
{
    int numA, numB;
    scanf("%u%u", &numA, &numB);
    printf("%u\n", middle(numA, numB));
    return 0;
}

int middle(int a, int b)
{

    return (a + b) / 2;
}
