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
    for(i = 2; i <= size; i++)
    {
        n = create_node(i);
        ptr->next = n;
        ptr = ptr->next;
    }
    return head;
}

// Delete a node at a given position in a linked list
node* delete(node *list, int pos)
{
    if (list == NULL || pos < 0)
    {
        return list;
    }
    else if (pos == 1)
    {
        list = list->next;
        return list;
    }
    else
    {
        int i = 1;
        node *curr = list;
        while (curr != NULL)
        {
            i++;
            if (i == pos)
            {
                curr->next = curr->next->next;
                return list;
            }
            curr = curr->next;
        }
    }
}

// Prints a list
void print(node *list)
{
    while(list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    node *list = create_list(5);
    print(list);
    delete(list, 3);
    print(list);
}
