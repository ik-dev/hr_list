#include "list.h"

// Compares two linked list
int compare(node *list1, node *list2)
{
    while (list1 && list2 && list1->data == list2->data)
    {
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 || list2)
        return 0;
    return 1;
}

int main()
{
    node *list_a = create_list(4), *list_b = create_list(5);
    printf("result: %d\n", compare(list_a, list_b));
    return 0;
}
