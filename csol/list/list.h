#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
}node;

node* create_node(int data);
node* create_list(int size);
void print(node* list);
void print_with_addr(node* list);
