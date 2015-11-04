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

// Delete a node at a given position in a linked list
node* delete(node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    else if (pos == 0)
    {
        head = head->next;
        return head;
    }
    else
    {
        int i = 1;
        node *curr = head;
        while (curr != NULL)
        {
            if (i == pos)
            {
                curr->next = curr->next->next;
                return head;
            }
            i++;
            curr = curr->next;
        }
    }
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
void print(node *head)
{
    for (;head != NULL; head = head->next)
        printf("%d\n", head->data);
}

// Print the elements of a linked list in reverse order
void reverse_print(node *head)
{
    if (head == NULL)
        return;
    reverse_print(head->next);
    printf("%d\n", head->data);
}

int main()
{
    node *head = NULL;

    head = insert_at_tail(head, 1);
    head = insert_at_tail(head, 2);
    head = insert_at_tail(head, 3);
    head = insert_at_tail(head, 4);
    head = insert_at_tail(head, 5);

    head = reverse(head);
    print(head);
}
