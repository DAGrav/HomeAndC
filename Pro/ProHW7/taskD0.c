#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define W_LENGHT 20
// Структура списка
typedef struct list {
    char word[W_LENGHT];
    struct list *next;
} list;

// Функция добавления элемента в список
list* add_to_list( list *head, const char *word) {
    list *new = calloc(1, sizeof(list));
    if (new == NULL) {
        return head;
    }
    strncpy(new->word, word, W_LENGHT-1);
    new->next = head;
    return new;
}

// Функция обмена данными между двумя элементами
void swap_elements(list *a, list *b) {
    char temp[W_LENGHT];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

// Функция сортировки списка (пузырьковая сортировка)
void sort_list(list *head) {
    if (head == NULL) return;
    int swapped;
    list *current;
    list *last = NULL;
    do {
        swapped = 0;
        current = head;
        while (current->next != last) {
            if (strcmp(current->word, current->next->word) > 0) {
                swap_elements(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Функция печати списка
void print_list(list *head)
{
    while(head)
    {
        printf("%s ",head->word);
        head = head->next;
    }
    printf("\n");
}

// Функция удаления всего списка
void delete_list(list *head) {
    list *current = head;
    list *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    list *head = NULL;
    char word[W_LENGHT];
    while (scanf("%19s", word) == 1) {
        // Проверяем последний символ
        int len = strlen(word);
        if (word[len - 1] == '.') {
            word[len - 1] = '\0'; // Удаляем точку
            head = add_to_list(head, word);
            break;
        }
        head = add_to_list(head, word);
    }
    if (head == NULL)
        return 0;
    //print_list(head);
    // Сортируем список
    sort_list(head);
    print_list(head);
    // Удаляем список
    delete_list(head);
    head = NULL;
    return 0;
}

