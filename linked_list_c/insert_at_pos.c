#include "list.h"

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

    return 0;
}
