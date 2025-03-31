#include <stdio.h>
#include "temp_api.h"

#define SIZE 3

int main(void)
{
    sensor_t temp[SIZE] = {0};
    temp[0].year = 2005;
    temp[0].month = 12;
    temp[0].day = 1;
    temp[0].hours = 4;
    temp[0].minutes = 50;
    temp[0].temp = -20;

    temp[1].year = 2005;
    temp[1].month = 12;
    temp[1].day = 1;
    temp[1].hours = 4;
    temp[1].minutes = 50;
    temp[1].temp = -16;

    temp[2].year = 2005;
    temp[2].month = 11;
    temp[2].day = 1;
    temp[2].hours = 4;
    temp[2].minutes = 20;
    temp[2].temp = -15;

    printf ("Average temp 2005 year: %.2f\n", AverageTemp(2005,0,&temp[0], SIZE));
    printf ("Min temp 2005 year: %hhi\n", MinTemp(2005,0,&temp[0], SIZE));
    printf ("Max temp nov month: %hhi\n", MaxTemp(2005,12,&temp[0], SIZE));
    return 0;
}

