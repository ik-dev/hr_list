#include "strlist.h"

node* create_node(char data)
{
    node* n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

node* create_list(char *str)
{
    if (sizeof(str) < 1)
        return NULL;
    int i;
    node *ptr, *n, *head = create_node(str[0]);
    ptr = head;
    for(i = 1; i < strlen(str); i++)
    {
        n = create_node(str[i]);
        ptr->next = n;
        ptr = ptr->next;
    }
    return head;
}

void print(node* list)
{
    for(;list != NULL; list = list->next)
        printf("%c", list->data);
    printf("\n");
}
