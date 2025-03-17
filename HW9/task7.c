
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 100};

void InputArray(int array[], int len);
void PrintArray (int array[], int len);
int compression(int a[], int b[], int N);

int main(void)
{
    int srcArray[SIZE] = {0};
    int destArray[SIZE] = {0};
    int compresElnts =0;
    InputArray (&srcArray[0], SIZE);
    compresElnts = compression(&srcArray[0], &destArray[0], SIZE);
    printf("%d\n", compresElnts);
    PrintArray (&destArray[0], compresElnts);
    return 0;
}

void InputArray(int array[], int len)
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

int compression(int a[], int b[], int N)
{
    int indexA = 0, indexB = 0;
    int base = 0, prev = 0;
    while (indexA <= N - 1 )
    {
        if(a[indexA] != base )
        {
            b[indexB++] = indexA - prev;
            base  = a[indexA];
            prev = indexA;
            indexA--;
        }
        else if(indexA == N - 1)
            b[indexB++] = indexA - prev + 1;
        indexA++;
    }
    return indexB;
}
