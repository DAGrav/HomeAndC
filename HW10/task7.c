#include <stdio.h>

enum {SIZE = 10000, SYMBA = 97, SYMBA_UP = 65, SYMBZ = 122, SYMBZ_UP = 90};

int main(void)
{
    char symbol;
    unsigned int index = 0, downCount = 0, upCount = 0 ;
    FILE* fileItem;
    fileItem = fopen ("input.txt", "r");
    while ((index < SIZE) && (fscanf(fileItem, "%c", &symbol) == 1) && (symbol != '\n'))
    {
        if ((SYMBA <= symbol) && (symbol <= SYMBZ))
            downCount++;
        if ((SYMBA_UP <= symbol) && (symbol <= SYMBZ_UP))
            upCount++;
    }
    fclose (fileItem);
    fileItem = fopen ("output.txt", "w");
    fprintf (fileItem, "%hu %hu\n", downCount, upCount);
    fclose (fileItem);
    return 0;
}
