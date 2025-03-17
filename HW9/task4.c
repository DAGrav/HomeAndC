
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 10000};

void InputArray(char array[]);
void print_digit(char array[]);

int main(void)
{
    char srcArray[SIZE] = {0};
    InputArray (&srcArray[0]);
    print_digit(&srcArray[0]);
    return 0;
}

void InputArray(char array[])
{
    scanf("%[^\n]",array);
}

void print_digit (char array[])
{
    int digits[10] = {};
    int index = 0;
    while (array[index] != 0 )
    {
        if ((array[index] -'0') >= 0 && (array[index] - '0') <= 9)
            digits[array[index] - '0']++;
        index++;
    }
    for(int i = 0; i < 10; i++ )
        if (digits[i] > 0)
            printf("%d %d\n", i, digits[i]);
}
