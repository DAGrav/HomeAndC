#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 5};

void InputArray(int array[], int len);
float Average(int array[], int len);

int main(void)
{
    int array [SIZE] = {0};
    InputArray(&array[0], SIZE);
    printf("%.3f\n", Average(&array[0], SIZE));
    return 0;
}

void InputArray(int array[], int len)
{
    for(int i = 0; i < len; i++ )
    {
        scanf ("%d", &array[i]);
    }
}

float Average(int array[], int len)
{
    float averNum = 0;
    for(int i = 0; i < len; i++ )
    {
        averNum += array[i];
    }
    return averNum /= len;
}
