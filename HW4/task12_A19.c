
#include <stdio.h>

int main(void)
{
    int numA, numB, numC;
    scanf("%d%d%d", &numA, &numB, &numC);
    if ((numA + numB) <= numC)
    {
        printf("%s\n","NO");
    }
    else if ((numB + numC) <= numA)
    {
        printf("%s\n","NO");
    }
    else if ((numC + numA) <= numB)
    {
        printf("%s\n","NO");
    }
    else
    {
        printf("%s\n","YES");
    }
    return 0;
}
