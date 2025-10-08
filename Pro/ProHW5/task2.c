#include <stdio.h>
#include <string.h>

#define MAXLEN 100010

// Функция для вычисления z-функции
void computeZFunction(const char *s, int *z, int n) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = (r - i + 1 < z[i - l]) ? (r - i + 1) : z[i - l];
        } else {
            z[i] = 0;
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int maxPrefixSuffix(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    // Создаем строку: str2 + '#' + str1
    char combined[MAXLEN + MAXLEN];
    sprintf(combined,"%s#%s", str2, str1);
    int totalLen = len1 + len2 + 1;
    int z[MAXLEN + MAXLEN];
    computeZFunction(combined, z, totalLen);
    for (size_t i = len2 + 1; i < totalLen; i++)
        if (z[i] == totalLen - i)
            return z[i];
    return 0;
}

int main() {
    char str1[MAXLEN], str2[MAXLEN];
    // Читаем две строки
    scanf("%s",str1);
    scanf("%s",str2);
    // Первое число: длина наибольшего префикса первой строки, являющегося суффиксом второй
    int first = maxPrefixSuffix(str2, str1);
    // Второе число: длина наибольшего суффикса первой строки, являющегося префиксом второй
    int second =  maxPrefixSuffix(str1, str2);
    printf("%d %d\n", first, second);
    return 0;
}
