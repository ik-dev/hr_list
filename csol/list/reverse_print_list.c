#include "list.h"

// Print the elements of a linked list in reverse order
void reverse_print_rec(node *list)
{
    if (list == NULL)
        return;
    reverse_print_rec(list->next);
    printf("%d[%p]->[%p] ", list->data, list, list->next);
}

void reverse_print(node *list)
{
    reverse_print_rec(list);
    printf("\n");
}

int main()
{
    node *list = create_list(5);

    print_with_addr(list);
    reverse_print(list);

    return 0;
}
