#include <stdio.h>

int is_prime(int n, int delitel);

int main(void)
{
    int num1;
    scanf("%u", &num1);
    printf("%s\n", is_prime(num1,2) > 0 ? "NO": "YES");
    return 0;
}
int is_prime(int n, int delitel)
{
    if (delitel == n)
        return 0;
    if (delitel > n)
        return delitel;
    if ( n % delitel == 0 )
        return delitel;
    delitel = is_prime (n, delitel + 1);
    return delitel;
}
