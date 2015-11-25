#include "list.h"

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

int main()
{
    node *list = create_list(5);
    printf("before delete: ");
    print(list);
    delete(list, 3);
    printf("after delete: ");
    print(list);
    return  0;
}
