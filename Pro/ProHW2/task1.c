#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;

void insert(list **head, void *address,
            size_t size, char *comment)
{
    list *tmp = malloc(sizeof(list));
    if (tmp == NULL)
    {
        printf ("%s", "Error malloc.");
        return;
    }
    tmp->next = *head;
    tmp->address = (uint64_t)address;
    tmp->size = size;
    sprintf(tmp->comment,"%s",comment);
    *head = tmp;
    printf("%lld ", tmp->address);
    printf("%lld\n",tmp->size);
}

uint64_t findMaxBlock(list *head)
{
    uint64_t address = 0;
    if (head == NULL)
        return address;
    size_t max_size = 0;
    while (head)
    {
        if (head->size > max_size)
        {
            address = head->address;
            max_size = head->size;
        }
        head = head->next;
    }
    return address;
}

int main(void)
{
    list *t_list=NULL;
    insert(&t_list, "test", 5, "Тест1");
    insert(&t_list, "test10", 7, "Тест2");
    insert(&t_list, "test1", 6, "Тест3");
    printf("%lld\n",findMaxBlock(t_list));
    return 0;
}

