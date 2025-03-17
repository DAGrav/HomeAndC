
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 1000, DIGIT_SIZE = 10};

void InputArray(char array[]);
void Account ( int count[], char array[], int lenArr);
void PrintAccount (int array[]);

int main(void)
{
    char srcArray[SIZE]={0};
    int digits[DIGIT_SIZE] = {};
    InputArray (&srcArray[0]);
    Account(&digits[0], &srcArray[0], SIZE);
    PrintAccount(&digits[0]);
    return 0;
}

void InputArray(char array[])
{
    scanf("%s",array);
}

void PrintAccount (int array[])
{
    for(int i = 0; i < DIGIT_SIZE; i++ )
        if (array[i] > 0)
            printf("%d %d\n", i, array[i]);
}

void Account (int count[],char array[], int lenArr)
{
    for(int i = 0; i < lenArr; i++ )
    {
        if (array[i] == 0)
            break;
        count[array[i] -'0']++;
    }
}
