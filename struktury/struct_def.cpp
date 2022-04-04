#include <iostream>

struct list_node{
    int val;
    list_node* next;
};

list_node* create_node(int val){
    list_node* node = new list_node;
    node->val = val;
    node->next = NULL;
    return node;
}

void insert_node(list_node** head, list_node* node){
    if (*head){
        if ((*head)->next){
            if ((*head)->val > node->val && (*head)->next->val < node->val){
                node->next = (*head)->next;
                (*head)->next = node;
            } else{
                insert_node(head, node);
            }
        } else{
            if ((*head)->val < node->val){
                node->next = *head;
                *head = node;
            } else{
                (*head)->next = node;
            }
        }
    }else{
        *head = node;
    }
}

void print_list(list_node* head){
    if (head){
        std::cout << head->val;
        if (head->next){
            std::cout << " -> ";
            print_list(head->next);
        } else{
            std::cout << std::endl;
        }
    }
}