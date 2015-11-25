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

// Compares two linked list
int compare(node *list1, node *list2)
{
    while (list1 && list2 && list1->data == list2->data)
    {
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 || list2)
        return 0;
    return 1;
}

int main()
{
    node *list_a = create_list(4), *list_b = create_list(5);
    printf("result: %d\n", compare(list_a, list_b));
}
