
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 100};

void InputArray(int array[], int len);
int find_max_array(int size, int a[]);

int main(void)
{
    int srcArray[SIZE] = {0};
    InputArray (&srcArray[0], SIZE);
    printf("%d\n",find_max_array(SIZE, &srcArray[0]));
    return 0;
}

void InputArray(int array[], int len)
{
    for(int i = 0; i < len; i++ )
    {
        scanf ("%d", &array[i]);
    }
}

int find_max_array(int size, int a[])
{
    int maxNum = a[size - 1];
    for (int i = 0; i < size-1; i++)
    {
        if (maxNum < a[i])
            maxNum = a[i];
    }
    return maxNum;
}
