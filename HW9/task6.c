#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 10};

void InputArray(int array[], int len);
int is_two_same(int size, int a[]);

int main(void)
{
    int srcArray[SIZE] = {0};
    InputArray (&srcArray[0], SIZE);
    printf("%s\n",(is_two_same(SIZE, &srcArray[0]) == 1) ? "YES" : "NO");
    return 0;
}

void InputArray(int array[], int len)
{
    for(int i = 0; i < len; i++ )
    {
        scanf ("%d", &array[i]);
    }
}

int is_two_same(int size, int a[])
{
    int index, item;
    for (int i = 1; i < size; i++)
    {
        item = a[i];
        index = i - 1;
        while(index >= 0 && a[index] > item)
        {
            a[index + 1] = a[index];
            index = index - 1;
        }
        a[index + 1] = item;
    }
    item = a[size - 1];
    index = size-2;
    while (index >= 0)
    {
        if (item == a[index])
            return 1;
        item = a[index];
        index--;
    }
    return 0;
}
