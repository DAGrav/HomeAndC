#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 5};

void InputArray(int array[], int len);
int MinIndex(int array[], int len);

int main(void)
{
    int array [SIZE];
    int minIndex;
    InputArray (&array[0], SIZE);
    minIndex = MinIndex(&array[0], SIZE);
    printf("%d\n", array[minIndex]);
    return 0;
}

void InputArray(int array[], int len)
{
    for(int i = 0; i < len; i++ )
    {
        scanf ("%d", &array[i]);
    }
}

int MinIndex(int array[], int len)
{
    int index = len-1;
    for(int i = len-2; i >= 0; i-- )
    {
        if (array[index] > array[i])
        {
            index = i;
        }
    }
    return index;
}
