#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    char data;
    struct _node *next;
}node;

node* create_node(char data);
node* create_list(char *str);
void print(node* list);

