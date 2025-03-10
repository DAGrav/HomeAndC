#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 10};

void InputArray(int array[], int len);
int MaxSumm(int array[], int len);

int main(void)
{
    int array [SIZE];
    InputArray (&array[0], SIZE);
    MaxSumm(&array[0], SIZE);
    printf("%d\n",  MaxSumm(&array[0], SIZE));
    return 0;
}

void InputArray( int array[], int len)
{
    for(int i = 0; i < len; i++ )
    {
        scanf ("%d", &array[i]);
    }
}
int MaxSumm(int array[], int len)
{
    int maxIndex1=0, maxIndex2=1;
    for(int i = 2; i < len; i++ )
    {
        if (array[i] > array[maxIndex1])
        {
           maxIndex2 = maxIndex1;
           maxIndex1 = i;
        }
        else if (array[i] > array[maxIndex2])
        {
           maxIndex2 = i;
        }
    }
    return array[maxIndex1] + array[maxIndex2];
}
