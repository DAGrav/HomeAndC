#include <unistd.h>
#include <stdlib.h>
#include <search.h>
#include <stdio.h>
#include "temp_api.h"
#include <locale.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, ".UTF8");// устанавливаем кодировку текста
    if(argc == 1) //Запускаем справку
    {
        PrintHelp(true, NULL);
        return 0;
    }
    char *opts = "hdm:f:";
    int opt, monthNum = 0;
    char *fileName = NULL;
    uint8_t showDamage = 0;
    while((opt = getopt(argc, argv, opts)) != -1)
    {   // вызываем getopt пока она не вернет -1
        switch(opt) {
        case 'd':// выводим номера ошибочных строк
            showDamage = 1;
            break;
        case 'h': // запускаем справку
            PrintHelp(false, argv[0]);
            return 0;
        case 'm': // выводим статистику по указанному месяцу
            monthNum = isMonth(optarg);
            if (monthNum < 1)
                PrintError(NOMONTH);
            //printf("%u\n", monthNum);
            break;
        case 'f': // входной файл для csv обработки
            if (isFile(optarg))
                fileName = optarg;
            break;
        }
    }
    if (fileName == NULL)
    {
        PrintError(NOFILENAME);
        return 0;
    }
    printf("Data processing...\n");
    uint8_t monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint8_t lastError = 0;
    FILE* file = fopen(fileName, "r");
    char line[30];
    unsigned int falseCount = 0;
    sensor_t sensor= {0};
    false_data falseItems = {};
    sensor_data dataItems = {};
    while (fgets(line, sizeof(line), file)) //читаем файл
    {
        if (sscanf( line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                    &sensor.year, &sensor.month, &sensor.day, &sensor.hours,
                    &sensor.minutes, &sensor.temp) == 6)//распознаем строками
        {
            if (!isValidDateTime(sensor, monthDays))
            {
                lastError = PushFalseData(&falseItems, falseCount + 1);
                PrintError(lastError);
            }
            else
                PushSensorData(&dataItems, &sensor);
        }
        else
        {
            lastError = PushFalseData(&falseItems, falseCount + 1);
            PrintError(lastError);

        }
        falseCount++;
        if (lastError > 0)
            return lastError;
    }
    fclose(file);
    printf("Good records = %u\n", dataItems.count);
    printf("Damaged records = %u\n", falseItems.count);
    qsort(dataItems.data, dataItems.count, sizeof(sensor_t), CompareDate);
    months_stat statItems = {};
    stat_t yearItem = {};
    yearItem.yrOrMnth = GetMonthStat (&statItems, &dataItems);//собираем статистику помесячно
    GetYearStat (&yearItem, &statItems);// собираем статистику года
    PrintMonthStat (&statItems,monthNum);
    PrintYearStat (&yearItem);
    if (showDamage > 0)//если указан был параметр 'd'
        PrintDamageNums(&falseItems);
    return 0;
}


