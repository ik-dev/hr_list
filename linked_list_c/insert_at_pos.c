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

// Insert a node at a specific position in a linked list
node* insert_at_pos(node* list, int data, int pos)
{
    node *n = create_node(data);
    if (list == NULL)
    {
        return n;
    }
    else if (pos == 0)
    {
        n->next = list;
        return n;
    }
    else
    {
        int i = 1;
        node *curr = list;
        while (curr != NULL)
        {
            if (i == pos)
            {
                n->next = curr->next;
                curr->next = n;
                return list;
            }
            i++;
            curr = curr->next;
        }
    }
    return list;
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
    node *list = NULL;

    list = insert_at_pos(list, 1, 0);
    print(list);
    list = insert_at_pos(list, 2, 1);
    print(list);
    list = insert_at_pos(list, 3, 1);
    print(list);
    list = insert_at_pos(list, 4, 2);
    print(list);
    list = insert_at_pos(list, 5, 0);
    print(list);
}
