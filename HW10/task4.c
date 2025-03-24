#include <stdio.h>
#include <string.h>

enum {TEXT_SIZE = 100, COUNT_SYMBOL = 26};

void countChar(char *text1, char *text2, int len1, int len2, int *count);

int main(void)
{
    char textA[TEXT_SIZE] = {0}, textB[TEXT_SIZE] = {0};
    int count[COUNT_SYMBOL] = {0}, lenTextA, lenTextB;
    FILE* fileItem;
    fileItem = fopen ("input.txt", "r");
    fscanf(fileItem, "%s%s", textA, textB);
    fclose (fileItem);
    lenTextA = strlen(textA);
    lenTextB = strlen(textB);
    countChar(textA, textB, lenTextA, lenTextB, count);
    fileItem = fopen ("output.txt", "w");
    for (int i = 0; i < COUNT_SYMBOL; i++)
        if (count[i] == 1)
            fprintf (fileItem, "%c ",i + 97);
    fprintf (fileItem, "%s","\n");
    fclose (fileItem);
    return 0;
}
void countChar(char *text1, char *text2, int len1, int len2, int *count)
{
    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            if (text1[i] == text2[j])
                count[text1[i] - 97]++;
}
