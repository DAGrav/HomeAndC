
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 10};

void InputArray(int array[], int len);
int SelArray (int sourceArray[], int destArray[], int len);
void PrintArray (int array[], int len);

int main(void)
{
    int srcArray [SIZE], dstArray [SIZE] = {0};
    int lenDestArray;
    InputArray (&srcArray[0], SIZE);
    lenDestArray = SelArray(&srcArray[0], &dstArray[0], SIZE);
    PrintArray(&dstArray[0], lenDestArray);
    return 0;
}

void InputArray( int array[], int len)
{
    for(int i = 0; i < len; i++ )
    {
        scanf ("%d", &array[i]);
    }
}

void PrintArray (int array[], int len)
{
    for(int i = 0; i < len; i++ )
        printf("%d ", array[i]);
    printf("\n");
}

int SelArray (int sourceArray [], int destArray[], int len)
{
    int lenDest = 0;
    for(int i = 0; i < len; i++ )
    {

        if ((sourceArray[i] > -100) && (sourceArray[i] < 100))
            continue;
        if (sourceArray[i] / 10 % 10 == 0)
        {
            destArray[lenDest] = sourceArray[i];
            lenDest++;
        }
    }
    return lenDest;
}
