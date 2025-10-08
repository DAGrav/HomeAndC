#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>
int main(void)
{
    int64_t digit = 0, max = LLONG_MIN;
    uint64_t counter = 0, result = 0 ;
    scanf( " %lldu", &counter );
    for (int i = 0; i < counter; i++)
    {
        scanf( " %lld", &digit );
        if (digit > max)
        {
            max = digit;
            result = 1;
        }
        else if (digit == max)
        {
            result++;
        }
    }
    printf("%lld\n", result);
    return 0;
}
