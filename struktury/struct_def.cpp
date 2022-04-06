#include <iostream>

struct list_node{
    int val;
    list_node* next;
};

list_node* create_list_node(int val){
    list_node* node = new list_node;
    node->val = val;
    node->next = NULL;
    return node;
}

void insert_list_node(list_node** head, list_node* node){
    if (*head){
        if ((*head)->val < node->val){
                node->next = *head;
                *head = node;
        } else if ((*head)->next){
            if ((*head)->val > node->val && (*head)->next->val < node->val){
                node->next = (*head)->next;
                (*head)->next = node;
            } else{
                insert_list_node(&((*head)->next), node);
            }
        } else{
            (*head)->next = node;
        }
    }else{
        *head = node;
    }
}

void delete_first_list_node(list_node** head){
    if (*head){
        if ((*head)->next){
            list_node* temp = (*head)->next;
            free(*head);
            *head = temp;
        } else{
            free(*head);
            *head = NULL;
        }
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
    } else{
        std::cout << "NULL" << std::endl;
    }
}

bool find_list_value(list_node* head, int val){
    if (head){
        if (head->val == val){
            return true;
        } else{
            if (find_list_value(head->next, val)){
                return true;
            } else{
                return false;
            }
        }
    } else{
        return false;
    }
}

struct tree_node{
    int val;
    tree_node* left;
    tree_node* right;
};

tree_node* create_tree_node(int val){
    tree_node* node = new tree_node;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_tree_node(tree_node** root, tree_node* node){
    if (*root){
        if ((*root)->val > node->val){
            insert_tree_node(&((*root)->left), node);
        } else{
            insert_tree_node(&((*root)->right), node);
        }
    } else{
        *root = node;
    }
}

bool find_tree_value(tree_node* root, int val){
    if (root){
        if (root->val == val){
            return true;
        } else{
            if (val < root->val){
                return find_tree_value(root->left, val);
            } else{
                return find_tree_value(root->right, val);
            }
        }
    } else{
        return false;
    }
}

void delete_tree_postorder(tree_node** root){
    if(*root){
        delete_tree_postorder(&((*root)->left));
        delete_tree_postorder(&((*root)->right));
        free(*root);
        *root = NULL;
    }
}