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

// Creates a list
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

// Reverse a linked list
node* reverse(node* head)
{
    node *prev, *next;
    prev = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Print the elements of a linked list
void print(node *list)
{
    for (;list != NULL; list = list->next)
        printf("%d ", list->data);
    printf("\n");
}

int main()
{
    node *list = create_list(5);
    print(list);
    list = reverse(list);
    print(list);
}
