#include <inttypes.h>

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temp;
} sensor_t;

float AverageTemp (uint16_t year, uint8_t month, sensor_t data[], size_t len);
int8_t MinTemp (uint16_t year, uint8_t month, sensor_t data[], size_t len);
int8_t MaxTemp (uint16_t year, uint8_t month, sensor_t data[], size_t len);


