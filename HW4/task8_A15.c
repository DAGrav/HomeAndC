
#include <stdio.h>

int main(void)
{
    int X1, Y1, X2, Y2;
    float K=0.0, B=0.0;
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    K = (float)(Y1 - Y2) / (X1 - X2);
    B = (float)(Y2 - K * X2);
    printf("%.2f %.2f\n", K, B);
    return 0;
}
