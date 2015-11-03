#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
}node;

// Insert a node at the tail of a linked list
node* tail(node* head, int data)
{
    node* n = (node *) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    if (head == NULL)
    {
        return n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
        return head;
    }
}

// Print the elements of a linked list
void display(node *head)
{
    while(head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main()
{
    node *head = NULL;

    head = tail(head, 1);
    head = tail(head, 2);
    head = tail(head, 3);

    display(head);
}
