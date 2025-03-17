
/*#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 10};

void InputArray(int array[], int len);
void sort_array (int size, int a[]);
void PrintArray (int array[], int len);

int main(void)
{
    int srcArray [SIZE];
    InputArray (&srcArray[0], SIZE);
    sort_array(SIZE, &srcArray[0]);
    PrintArray(&srcArray[0], SIZE);
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
}*/

void sort_array (int size, int a[])
{

    int index, newItem;
    for (int i = 1; i < size; i++)
    {
        newItem = a[i];
        index = i - 1;
        while(index >= 0 && a[index] > newItem)
        {
            a[index + 1] = a[index];
            index = index - 1;
        }
        a[index + 1] = newItem;
    }
}
