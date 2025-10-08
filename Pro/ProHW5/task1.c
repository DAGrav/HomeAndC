#include <stdio.h>
#include <string.h>

int countNumbers(const char* numStr) {
    int len = strlen(numStr);
    if (len < 3) return 0;
    int counter = 0;
    int cutNum[1000] = {0};
    for (int i = 0; i < len - 2; i++) {
        int digit1 = numStr[i] - '0';
        if (digit1 == 0) continue; // Первая цифра не может быть 0
        // Ищем оставшиеся две цифры
        for (int j = i + 1; j < len - 1; j++) {
            int digit2 = numStr[j] - '0';
            for (int k = j + 1; k < len; k++) {
                int digit3 = numStr[k] - '0';
                int number = digit1 * 100 + digit2 * 10 + digit3;

                if (!cutNum[number]) {
                    cutNum[number] = 1;
                    counter++;
                }
            }
        }
    }
    return counter;
}
int main() {
    char input[1000];
    scanf("%s", input);
    int result = countNumbers(input);
    printf("%d\n", result);
    return 0;
}
