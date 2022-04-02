#include <iostream>

struct list_node{
    int val;
    list_node* next;
};

list_node* create_node(int val){
    list_node* node;
    node = (list_node*) malloc(sizeof(list_node));
    node->val = val;
    node->next = NULL;
    return node;
}

