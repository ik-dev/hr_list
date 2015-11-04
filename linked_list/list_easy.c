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
node* insert_at_head(node* head, int data)
{
    node* n = create_node(data);
    n->next = head;
    return n;
}

// Insert a node at the tail of a linked list
node* insert_at_tail(node* head, int data)
{
    node* n = create_node(data);
    if (head == NULL)
    {
        return n;
    }
    node *curr;
    for (curr = head; curr->next != NULL; curr = curr->next);
    curr->next = n;
    return head;
}

// Insert a node at a specific position in a linked list
node* insert_at_pos(node* head, int data, int pos)
{
    node *n = create_node(data);
    if (head == NULL)
    {
        return n;
    }
    else if (pos == 0)
    {
        n->next = head;
        return n;
    }
    else
    {
        int i = 1;
        node *curr = head;
        while (curr != NULL)
        {
            if (i == pos)
            {
                n->next = curr->next;
                curr->next = n;
                return head;
            }
            i++;
            curr = curr->next;
        }
    }
    return head;
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

    head = insert_at_pos(head, 1, 0);
    head = insert_at_pos(head, 2, 1);
    head = insert_at_pos(head, 3, 2);
    head = insert_at_pos(head, 4, 1);
    head = insert_at_pos(head, 5, 1);

    display(head);
}
