#include "list.h"

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

int main()
{
    node *list = create_list(5);

    print_with_addr(list);
    list = reverse(list);
    print_with_addr(list);

    return 0;
}
