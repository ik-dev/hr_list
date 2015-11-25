#include "list.h"

// Creates a linked list node
node* create_node(int data)
{
    node* n = (node *) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Creates a linked list
node* create_list(int size)
{
    if (size < 1)
        return NULL;
    node* head = create_node(1);
    node *ptr = head;
    node *n;
    ptr = head;
    int i;
    for(i=2; i <= size; i++)
    {
        n = create_node(i);
        ptr->next = n;
        ptr = ptr->next;
    }
    return head;
}

// Print the elements of a linked list
void print(node *list)
{
    for (;list != NULL; list = list->next)
        printf("%d ", list->data);
    printf("\n");
}

// Print the elements of a linked list with address space
void print_with_addr(node *list)
{
    for (;list != NULL; list = list->next)
        printf("%d[%p]->[%p] ", list->data, list, list->next);
    printf("\n");
}
