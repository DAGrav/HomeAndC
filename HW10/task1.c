
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 100, COUNT = 3};

int main(void)
{
    char text[SIZE] = {0}, c;
    size_t i = 0, count = COUNT;
    FILE* fileItem;
    fileItem = fopen ("input.txt", "r");
    while ((i < SIZE) && (fscanf(fileItem, "%c", &c) == 1) && (c != '\n'))
    {
        text[i] = c;
        i++;
    }
    fclose (fileItem);
    fileItem = fopen ("output.txt", "w");
    for (; count > 1; count--)
        fprintf (fileItem, "%s, ", text);
    fprintf (fileItem, "%s %llu\n", text, i);
    fclose (fileItem);
    return 0;
}
