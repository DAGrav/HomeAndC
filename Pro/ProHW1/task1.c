#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
int main(void)
{
    char symbol='\0', number = 0;
    uint64_t index = 0;
    scanf( "%lldu", &index );
   while (symbol != '.')
    {
       scanf("%c", &symbol);
       if ((symbol >= 97) && (symbol <= 122))
       {
       number = symbol - 'a';
       number = (number + index) % 26;
       symbol = 'a' + number;
       }
       else if ((symbol >= 65) && (symbol <= 90))
       {
       number = symbol - 'A';
       number = (number + index) % 26;
       symbol = 'A' + number;
       }
       printf("%c", symbol);
    }
    return 0;
}

