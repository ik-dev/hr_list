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
    for(i = 2; i <= size; i++)
    {
        n = create_node(i);
        ptr->next = n;
        ptr = ptr->next;
    }
    return head;
}

// Deep copies a linked list
node* deep_copy(node *head)
{
    node *new_head = NULL;
    node *new_tail = NULL;
    while (head != NULL)
    {
        if(new_head == NULL)
        {
            new_head = create_node(head->data);
            new_tail = new_head;
        }
        else
        {
            new_tail->next = create_node(head->data);
            new_tail = new_tail->next;
        }
        head = head->next;
    }
    return new_head;
}

// Prints given list with there address space
void print_list(node* list)
{
    while(list)
    {
        printf("%d[%p] ", list->data, list);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    node *list_a= create_list(5), *list_b, *list_c;
    list_b = deep_copy(list_a);
    list_c = list_a;
    print_list(list_a);
    print_list(list_b);
    print_list(list_c);
}
