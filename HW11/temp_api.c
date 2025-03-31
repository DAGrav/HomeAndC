//#include <stdio.h>
#include <inttypes.h>
#include "temp_api.h"

#define INT8MIN -128;
#define INT8MAX 127;

float AverageTemp (uint16_t year, uint8_t month, sensor_t data[], size_t len)
{
    float average = 0.0;
    size_t counter = 0;

    if (len < 1)
        return average;
    if (month == 0)
    {
        while (len > 0 && len--)
            if (data[len].year == year)
            {
                counter++;
                average += data[len].temp;
            }
    }
    else
        while (len > 0 && len--)
            if (data[len].year == year && data[len].month == month)
            {
                counter++;
                average += data[len].temp;
            }
    if ( counter > 0)
        return (float)(average / counter);
    return average;
}

int8_t MinTemp (uint16_t year, uint8_t month, sensor_t data[], size_t len)
{
    int8_t minValue = INT8MAX;
    uint8_t flag = 0;

    if (len < 1)
        return 0;
    if (month == 0)
    {
        while (len > 0 && len--)
            if (data[len].year == year)
            {
                flag = 1;
                if (data[len].temp < minValue)
                    minValue = data[len].temp;
            }
    }
    else
        while (len > 0 && len--)
            if (data[len].year == year && data[len].month == month)
            {
                flag = 1;
                if (data[len].temp < minValue)
                    minValue = data[len].temp;
            }
    if (flag > 0)
        return minValue;
    return 0;
}

int8_t MaxTemp (uint16_t year, uint8_t month, sensor_t data[], size_t len)
{
    int8_t maxValue = INT8MIN;
    uint8_t flag = 0;

    if (len < 1)
        return 0;
    if (month == 0)
    {
        while (len > 0 && len--)
            if (data[len].year == year)
            {
                flag = 1;
                if (data[len].temp > maxValue)
                    maxValue = data[len].temp;
            }
    }
    else
        while (len > 0 && len--)
            if (data[len].year == year && data[len].month == month)
            {
                flag = 1;
                if (data[len].temp > maxValue)
                    maxValue = data[len].temp;
            }
    if (flag > 0)
        return maxValue;
    return 0;
}
