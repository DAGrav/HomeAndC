#include <stdio.h>
#include <inttypes.h>

int machFx(int numX);
int main(void)
{
    char cNum;
    int num = 0;
    int16_t factor = 1;
    int max = 0;
    while ((cNum = getchar ()) != '\n')
    {
        if (cNum == '-')
        {
            factor = -1;
        }
        else if (cNum >= '0' && cNum <= '9')
        {
            num = num * 10 + cNum - '0';
        }
        else
        {
            num = machFx(num * factor);
            max = max < num ? num: max;
            num = 0;
            factor = 1;
        }
    }
    printf("%d\n", max);
    return 0;
}

int machFx(int numX)
{
    if ((numX >= -2) && (numX < 2))
    {
        return numX * numX;
    }
    else if (numX >= 2)
    {
        return numX * numX + 4 * numX + 5;
    }
    else
    {
        return 4;
    }
}
