#include <iostream>
#include <algorithm>
#include <vector>

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

void delete_list(list_node** head){
    if (*head){
        list_node* temp = (*head)->next;
        free(*head);
        *head = temp;
        delete_list(head);
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

int height_of_tree(tree_node* root, int h=0){
    if (root)
        return std::max(height_of_tree(root->left, h+1), height_of_tree(root->right, h+1));
    else 
        return h ? h-1 : h;
}

void read_tree_inorder(tree_node* root, std::vector<int>* vec){
    if (root){
        read_tree_inorder(root->left, vec);
        (*vec).push_back(root->val);
        read_tree_inorder(root->right, vec);
    }
}

void binary_avl_building(tree_node** root, std::vector<int> vec, int start, int end){
    if (start <= end && vec.size()){
        int mid = (start + end) / 2;
        *root = create_tree_node(vec[mid]);
        binary_avl_building((&(*root)->left), vec, start, mid-1);
        binary_avl_building((&(*root)->right), vec, mid+1, end);
    }
}