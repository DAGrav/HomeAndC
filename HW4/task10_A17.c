
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint8_t monthNum;
    scanf("%hhu", &monthNum);
    monthNum = (monthNum % 12) / 3; /* Определяем порядковый номер
    времени года.*/
    if (monthNum == 1)
    {
        printf("%s\n", "spring");
    }
    else if (monthNum == 2)
    {
        printf("%s\n", "summer");
    }
    else if (monthNum == 3)
    {
        printf("%s\n", "autumn");
    }
    else
    {
        printf("%s\n", "winter");
    }
    return 0;
}
