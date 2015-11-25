#include "strlist.h"

int compare(node* list1, node* list2)
{
    while(list1 && list2 && list1->data == list2->data)
    {
        list1 = list1->next;
        list2 = list2->next;
    }
    if(list1 && list2)
        return (list1->data > list2->data) ? 1 : -1;
    if(list1 && !list2)
        return 1;
    if(!list1 && list2)
        return -1;
    return 0;
}

int main()
{
    node *list_a = create_list("ibad"), *list_b = create_list("khan");
    print(list_a);
    print(list_b);
    printf("result of comparision: %d\n", compare(list_a, list_b));
    return 0;
}
