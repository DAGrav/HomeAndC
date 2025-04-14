#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include "temp_api.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define INT8MIN -128;
#define INT8MAX 127;
#define MAXYEAR 3000;
#define ALLOC_COUNT 10;

void PrintHelp (bool mode, const char *fileName)
{
    if (mode) {
        printf("To get help, run the application with the key -h.\n");
        return;
    }
    printf("Usage:%s [options] [parameters]\n", fileName);
    printf("Options:\n-h \t\t Print this message. \n");
    printf("-m Month \t Display statistics for the specified month number. \n");
    printf("-f \"File\" \t Input csv file to be processed. \n");
    printf("-d \t\t Display the number of the damaged line. \n");
}

void PrintMonthStat (months_stat *statItems, uint8_t month)
{
    printf("\t========================================================\n");
    printf("\t|Month\t|\t%-s\t|\t%-s\t|\t%-s|\n","MinTemp","MaxTemp","AvgTemp");
    for (unsigned int i = 0; i < statItems->count; i++)
    {
        if (month < 1)
        {
            printf("\t--------------------------------------------------------\n");
            printf("\t|%4hu\t|\t%+4hhd\t|\t%+4hhd\t|\t%+6.2f |\n",
                   statItems->data[i].yrOrMnth, statItems->data[i].minTemp,
                   statItems->data[i].maxTemp, statItems->data[i].averTemp);
        }
        else if (statItems->data[i].yrOrMnth == month)
        {
            printf("\t--------------------------------------------------------\n");
            printf("\t|%4hu\t|\t%+4hhd\t|\t%+4hhd\t|\t%+6.2f |\n",
                   statItems->data[i].yrOrMnth, statItems->data[i].minTemp,
                   statItems->data[i].maxTemp, statItems->data[i].averTemp);
            break;
        }
    }
    printf("\t========================================================\n");
}

void PrintYearStat (stat_t *statItems)
{
    printf("\nYear: %hu\n",statItems->yrOrMnth);
    printf("Minimum temperature of the year: %+hhd\n",statItems->minTemp);
    printf("Maximum temperature of the year: %+hhd\n",statItems->maxTemp);
    printf("Average temperature of the year: %+0.2f\n",statItems->averTemp);
}

void PrintDamageNums (false_data *Items)
{
    printf("Damage lines:\n");
    printf("\t=============================\n");
    for (unsigned int i = 0; i < Items->count; i++)
    {


        printf("\tDamage line number: %u\n",Items->data[i]);
    }
    printf("\t=============================\n");
}

void PrintError (uint8_t errorNum)
{
    switch (errorNum) {
    case NOMONTH:
        printf("The \"Month\" parameter is incorrect.\n");
        break;
    case NOFILENAME:
        printf("The \"File\" parameter is incorrect or the file does not exist.\n");
        break;
    case ALLOC_MEM:
        printf("Error allocation memory.\n");
        break;
    }
    return;
}

uint8_t isMonth (const char *month)
{
    if (strlen(month) > 2)
        return 0;
    uint8_t monthNum = atoi(month);
    if ((monthNum < 1) || (monthNum > 12))
        return 0;
    return monthNum;
}

bool isFile (const char *fileName)
{
    if (access(fileName, F_OK) == 0)
        return true;
    return false;
}

bool isValidDateTime(sensor_t sensorItem, uint8_t monthDaysItem[])
{
    // Проверка года
    uint16_t maxYear = MAXYEAR;
    if ((sensorItem.year < 1) || (sensorItem.year > maxYear))
        return false;
    if ((sensorItem.month < 1) || (sensorItem.month > 12))
        return false;
    //Если год високосный
    monthDaysItem[1] = 28;
    if (((sensorItem.year % 4 == 0) && (sensorItem.year % 100 != 0)) || (sensorItem.year % 400 == 0))
        monthDaysItem[1]++;
    if ((sensorItem.day > monthDaysItem[sensorItem.month - 1]) || (sensorItem.day < 1))
        return false;
    if ((sensorItem.hours > 23) || (sensorItem.minutes > 59))
        return false;
    return true;
}

uint8_t PushSensorData (sensor_data *item, sensor_t *value)
{
    if (item->count >= item->capacity)
    {
        item->capacity += ALLOC_COUNT;
        item->data = realloc(item->data, sizeof(sensor_t)*item->capacity);
        if(item->data == NULL)
        {
            return ALLOC_MEM;
        }
    }
    item->data[item->count] = *value;
    item->count++;
    return 0;
}

uint8_t PushFalseData (false_data *item, unsigned int value)
{
    if (item->count >= item->capacity)
    {
        item->capacity+=ALLOC_COUNT;
        item->data =realloc(item->data, sizeof(unsigned int)*item->capacity);
        if(item->data == NULL)
        {
            return ALLOC_MEM;
        }
    }
    item->data[item->count] = value;
    item->count++;
    return 0;
}

uint8_t PushMonthsData (months_stat *item, stat_t value)
{
    if (item->count >= item->capacity)
    {
        item->capacity+=ALLOC_COUNT;
        item->data =realloc(item->data, sizeof(stat_t)*item->capacity);
        if(item->data == NULL)
        {
            return ALLOC_MEM;
        }
    }
    item->data[item->count] = value;
    item->count++;
    return 0;
}

int CompareDate(const void* x,const void* y)
{
    sensor_t* a = (sensor_t*)x;
    sensor_t* b = (sensor_t*)y;
    if((a->year - b->year) != 0)
        return a->year - b->year;
    else if ((a->month - b->month) != 0)
        return a->month - b->month;
    else if ((a->day - b->day) != 0)
        return a->day - b->day;
    else if ((a->hours - b->hours) != 0)
        return a->hours - b->hours;
    else if ((a->minutes - b->minutes) != 0)
        return a->minutes - b->minutes;
    else if ((a->temp - b->temp) != 0)
        return a->temp - b->temp;
    return 0;
}

void GetYearStat (stat_t *yearItem, months_stat* monthItems)
{
    if (monthItems == NULL)
        return;
    if (monthItems->count == 0)
        return;
    unsigned int index = 0, averCount = 0;
    yearItem->maxTemp = INT8MIN;
    yearItem->minTemp = INT8MAX;
    yearItem->averTemp = 0.0;

    while (index < monthItems->count)
    {
        yearItem->maxTemp = GetMax(yearItem->maxTemp, monthItems->data[index].maxTemp);
        yearItem->minTemp = GetMin(yearItem->minTemp, monthItems->data[index].minTemp);
        yearItem->averTemp += monthItems->data[index].averTemp;
        averCount++;
        if (index == monthItems->count-1)
        {
            yearItem->averTemp = yearItem->averTemp/averCount;
        }
        index++;
    }
}

uint16_t GetMonthStat (months_stat* items, sensor_data *sensorItems)
{
    uint16_t year = 0;
    if (sensorItems == NULL)
        return year;
    if (sensorItems->count == 0)
        return year;
    uint8_t lastError = 0;
    stat_t mntItem;
    unsigned int index = 0, averCount = 0;
    mntItem.maxTemp = INT8MIN;
    mntItem.minTemp = INT8MAX;
    mntItem.averTemp = 0.0;
    mntItem.yrOrMnth = 0;
    while (index < sensorItems->count)
    {
        if (index == 0)
            mntItem.yrOrMnth = sensorItems->data[index].month;
        if (mntItem.yrOrMnth != sensorItems->data[index].month)
        {
            mntItem.averTemp = mntItem.averTemp/averCount;
            lastError = PushMonthsData(items, mntItem);
            PrintError(lastError);
            mntItem.maxTemp = INT8MIN;
            mntItem.minTemp = INT8MAX;
            mntItem.averTemp = 0.0;
            averCount = 0;
        }
        mntItem.yrOrMnth = sensorItems->data[index].month;
        mntItem.maxTemp = GetMax(mntItem.maxTemp, sensorItems->data[index].temp);
        mntItem.minTemp = GetMin(mntItem.minTemp, sensorItems->data[index].temp);
        mntItem.averTemp += sensorItems->data[index].temp;
        averCount++;
        if (index == sensorItems->count-1)
        {
            mntItem.averTemp = mntItem.averTemp/averCount;
            year = sensorItems->data[index].year;
            lastError = PushMonthsData(items, mntItem);
            PrintError(lastError);
        }
        if (lastError > 0)
            break;
        index++;
    }
    return year;
}

int8_t GetMin (int8_t firstVal, int8_t secondVal)
{
    return (firstVal < secondVal) ? firstVal : secondVal;
}

int8_t GetMax(int8_t firstVal, int8_t secondVal)
{
    return (firstVal > secondVal) ? firstVal : secondVal;
}

