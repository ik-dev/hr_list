#include "list.h"

// Insert a node at the head of a linked list
node* insert_at_head(node* list, int data)
{
    node* n = create_node(data);
    n->next = list;
    return n;
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

    return 0;
}
