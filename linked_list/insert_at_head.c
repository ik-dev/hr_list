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

// Insert a node at the head of a linked list
node* insert_at_head(node* list, int data)
{
    node* n = create_node(data);
    n->next = list;
    return n;
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
    node *list = NULL, *another;

    list = insert_at_head(list, 1);
    print(list);
    list = insert_at_head(list, 2);
    print(list);
    list = insert_at_head(list, 3);
    print(list);
    list = insert_at_head(list, 4);
    print(list);
    list = insert_at_head(list, 5);
    print(list);
}
