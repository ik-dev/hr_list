#include "list.h"

// Insert a node at the tail of a linked list
node* insert_at_tail(node* list, int data)
{
    node* n = create_node(data);
    if (list == NULL)
    {
        return n;
    }
    node *curr;
    for (curr = list; curr->next != NULL; curr = curr->next);
    curr->next = n;
    return list;
}

int main()
{
    node *list = NULL;

    list = insert_at_tail(list, 1);
    print(list);
    list = insert_at_tail(list, 2);
    print(list);
    list = insert_at_tail(list, 3);
    print(list);
    list = insert_at_tail(list, 4);
    print(list);
    list = insert_at_tail(list, 5);
    print(list);

    return 0;
}
