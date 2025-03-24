
#include <stdio.h>
#include <inttypes.h>

enum {CHAR_A = 65};

int main(void)
{
    char symbol = CHAR_A;
    uint8_t count = 0, index = 0;
    FILE* fileItem;
    fileItem = fopen ("input.txt", "r");
    if (fscanf (fileItem, "%hhu", &count) != 1)
    {
        fclose (fileItem);
        return 1;
    }
    if ((count == 0) || (count % 2 == 1))
        return 1;
    fileItem = fopen ("output.txt", "w");
    while (index < count)
    {
        if ((index + 1) % 2 == 0)
            fprintf (fileItem, "%hhu", (index & 7) + 1);
        else
            fprintf (fileItem, "%c", symbol++);
        index++;
    }
    fprintf (fileItem, "%s","\n");
    fclose (fileItem);
    return 0;
}
