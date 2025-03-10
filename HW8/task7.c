
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 10};

void InputArray(int array[], int len);
void Reverse(int array[], int len);
void PrintArray (int array[], int len);

int main(void)
{
    int array [SIZE] = {0};
    InputArray(&array[0], SIZE);
    Reverse(&array[0], SIZE);
    PrintArray(&array[0], SIZE);
    return 0;
}

void PrintArray (int array[], int len)
{
    for(int i = 0; i < len; i++ )
        printf("%d ", array[i]);
    printf("\n");
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InputArray(int array[], int len)
{
    for(int i = 0; i < len; i++ )
        scanf ("%d", &array[i]);
}

void Reverse(int array[], int len)
{
    for(int i = 0; i < len/5; i++ )
    {
        swap (array + i,array + len/2 - 1 - i );
        swap (array + len / 2 + i,array + len - 1 - i);
    }
}

