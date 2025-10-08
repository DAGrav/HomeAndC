#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 255

// Структура стека
typedef struct {
    int data[MAXLEN];
    int top;
} Stack;

// Инициализация стека
void initStack(Stack *s) {
    s->top = -1;
}

// Проверка на пустоту
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Добавление элемента
void push(Stack *s, int value) {
    if (s->top < MAXLEN - 1) {
        s->data[++(s->top)] = value;
    }
}

// Извлечение элемента
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return 0; // В случае ошибки
}

// Просмотр верхнего элемента
int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return 0;
}

// Функция для вычисления
int evaluate(char* expression) {
    Stack stack;
    initStack(&stack);
    char* token = strtok(expression, " ");
    while (token != NULL) {
        // Если токен - число
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            int num = atoi(token);
            push(&stack, num);
        }
        // Если токен - оператор
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result = 0;
            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b != 0) {
                        result = a / b;
                    }
                    break;
            }

            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expression[MAXLEN];
    // Читаем всю строку
    fgets(expression, MAXLEN, stdin);

    // Убираем символ новой строки
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluate(expression);
    printf("%d\n", result);

    return 0;
}
