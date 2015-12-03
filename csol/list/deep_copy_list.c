#include "list.h"

// Deep copies a linked list
node* deep_copy(node *head)
{
    node *new_head = NULL;
    node *new_tail = NULL;
    while (head != NULL)
    {
        if(new_head == NULL)
        {
            new_head = create_node(head->data);
            new_tail = new_head;
        }
        else
        {
            new_tail->next = create_node(head->data);
            new_tail = new_tail->next;
        }
        head = head->next;
    }
    return new_head;
}

int main()
{
    node *list_a= create_list(5), *list_b, *list_c;
    list_b = deep_copy(list_a);
    list_c = list_a;

    printf("original list: ");
    print_with_addr(list_a);
    printf("deep copy list: ");
    print_with_addr(list_b);
    printf("shallow copy list: ");
    print_with_addr(list_c);

    return 0;
}
