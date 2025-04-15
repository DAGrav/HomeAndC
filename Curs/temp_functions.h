#include <inttypes.h>
#include <stdbool.h>
typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temp;
} sensor_t;

typedef struct
{
    uint16_t yrOrMnth;
    float averTemp;
    int8_t minTemp;
    int8_t maxTemp;
} stat_t;

typedef struct
{
    stat_t *data;
    unsigned int capacity;
    unsigned int count;
} months_stat;

typedef struct
{
    sensor_t *data;
    unsigned int capacity;
    unsigned int count;
} sensor_data;

typedef struct
{
    unsigned int *data;
    unsigned int capacity;
    unsigned int count;
} false_data;

enum errorId {NOMONTH = 1, NOFILENAME = 2, ALLOC_MEM = 3};
void PrintHelp (bool mode, const char* fileName);
void PrintMonthStat (months_stat* statItems, uint8_t month);
void PrintYearStat (stat_t* statItems);
void PrintDamageNums (false_data* Items, uint8_t countPrint);
void PrintError (uint8_t errorNum);
void GetYearStat (stat_t* yearItem, months_stat* monthItems);
bool isFile (const char* fileName);
bool isValidDateTime(sensor_t sensorItem, uint8_t monthDaysItem[]);
int CompareDate(const void* x, const void* y);
uint16_t GetMonthStat (months_stat* items, sensor_data* sensorItems);
uint8_t isMonth (const char* month);
uint8_t isPrintArg (const char *printArg);
uint8_t PushSensorData (sensor_data* item, sensor_t* value);
uint8_t PushMonthsData (months_stat* item, stat_t value);
uint8_t PushFalseData (false_data* item, unsigned int value);
int8_t GetMin (int8_t firstVal, int8_t secondVal);
int8_t GetMax(int8_t firstVal, int8_t secondVal);
