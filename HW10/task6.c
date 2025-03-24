
#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 1000};
uint8_t Palindrom (char* text, uint16_t textLen);

int main(void)
{
    char text[SIZE] = {0}, symbol;
    uint16_t index = 0;
    FILE* fileItem;
    fileItem = fopen ("input.txt", "r");
    while ((index < SIZE) && (fscanf(fileItem, "%c", &symbol) == 1) && (symbol != '\n'))
    {
        text[index++] = symbol;
    }
    fclose (fileItem);
    fileItem = fopen ("output.txt", "w");
    if (Palindrom (&text[0], index) == 1)
    fprintf (fileItem, "YES\n");
    else
    fprintf (fileItem, "NO\n");
    fclose (fileItem);
    return 0;
}

uint8_t Palindrom (char* text, uint16_t textLen)
{
    for (int i = 0, j = textLen - 1; i < j; ++i, --j)
        if (text[i] != text[j])
        return 0;
    return 1;
}
