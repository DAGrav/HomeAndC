#include <stdio.h>

enum {SIZE = 1000};

int main(void)
{
    char text[SIZE] = {0}, symbol;
    unsigned int index = 0;
    FILE* fileItem;
    fileItem = fopen ("input.txt", "r");
    while ((index < SIZE) && (fscanf(fileItem, "%c", &symbol) == 1) && (symbol != '\n'))
    {
        text[index++] = symbol;
    }
    fclose (fileItem);
    fileItem = fopen ("output.txt", "w");
    for (int j=0; j < index - 1; j++)
        if (text[j] == text[index - 1])
            fprintf (fileItem, "%d ", j);
    fprintf (fileItem, "%s","\n");
    fclose (fileItem);
    return 0;
}
