#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int convert(int num, int baseSys);
int main(void)
{
    int num1, baseSys;
    scanf("%d%d", &num1, &baseSys);
    printf("%d\n", convert(num1, baseSys));
    return 0;
}

int convert(int num, int baseSys)
{
    int result = 0;
    for (int i = 0; 1 <= num; i++)
    {
        result+=(num % baseSys) * pow(10., i);
        num /= baseSys;
    }
    return result;
}
