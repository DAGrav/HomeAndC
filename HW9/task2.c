/*#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 21};

void InputArray(int array[], int len);
void sort_even_odd (int n, int a[]);
void PrintArray (int array[], int len);

int main(void)
{
    int srcArray [SIZE];
    InputArray (&srcArray[0], SIZE);
    sort_even_odd(SIZE, &srcArray[0]);
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

void sort_even_odd (int n, int a[])
{
    int temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0) temp[j++] = a[i];
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0) temp[j++] = a[i];
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}
