#include <stdio.h>

void print_num(int limit, int numK);

int main(void)
{
    int limit;
    scanf("%d", &limit);
    print_num(limit, 1);
    return 0;
}
void print_num(int limit, int numK)
{
    for (int i = 1 ; i <= numK; i++)
    {
        printf("%d ",numK);
        limit--;
        if (limit < 1)
        {
            return;
        }
    }
    print_num(limit,  numK + 1);
}
