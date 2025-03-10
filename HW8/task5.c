
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 10};

void InputArray(int array[], int len);
size_t PosSumm(int array[], int len);

int main(void)
{
    int array [SIZE];
    InputArray (&array[0], SIZE);
    printf("%lld\n",  PosSumm(&array[0], SIZE));
    return 0;
}

void InputArray( int array[], int len)
{
    for(int i = 0; i < len; i++ )
    {
        scanf ("%d", &array[i]);
    }
}

size_t PosSumm(int array[], int len)
{
    size_t summ = 0;
    for(int i = 0; i < len; i++ )
    {
        if (array[i] > 0)
        {
            summ += array[i];
        }
    }
    return summ;
}
