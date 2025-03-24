#include <stdio.h>

enum {SIZE = 1000, SYMBA = 97, SYMBA_UP = 65};

int main(void)
{
    char text[SIZE] = {0}, symbol;
    unsigned int index = 0;
    FILE* fileItem;
    fileItem = fopen ("input.txt", "r");
    while ((index < SIZE) && (fscanf(fileItem, "%c", &symbol) == 1) && (symbol != '\n'))
    {
        if ((symbol == SYMBA) || (symbol == SYMBA_UP))
        text[index++] = ++symbol;
        else if ((symbol == SYMBA+1) || (symbol == SYMBA_UP+1))
        text[index++] = --symbol;
        else
        text[index++] = symbol;
    }
    fclose (fileItem);
    fileItem = fopen ("output.txt", "w");
    fprintf (fileItem, "%s\n", text);
    fclose (fileItem);
    return 0;
}

