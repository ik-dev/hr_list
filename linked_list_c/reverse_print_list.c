#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
}node;

// Creates a linked list node
node* create_node(int data)
{
    node* n = (node *) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

node* create_list(int size)
{
    if (size < 1)
        return NULL;
    node *ptr, *n, *head = create_node(1);
    ptr = head;
    int i;
    for(i=2; i<=size; i++)
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

// Print the elements of a linked list in reverse order
void reverse_print_rec(node *list)
{
    if (list == NULL)
        return;
    reverse_print_rec(list->next);
    printf("%d ", list->data);
}

void reverse_print(node *list)
{
    reverse_print_rec(list);
    printf("\n");
}

int main()
{
    node *list = create_list(5);
    print(list);
    reverse_print(list);
}
