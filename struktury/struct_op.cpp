#include <iostream>
#include <ctime>
#include <cstdlib>
#include "struct_def.cpp"

#define MAXLEN 200000

using namespace std;

void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void generate_ascending_array(int arr[], int len){
    for (int i=0; i<len; i++){
        arr[i] = i + 1;
    }
}

void shuffle_arr(int arr[], int size){
    for (int i=0; i<size; i++){
        int idx1 = rand() % size;
        int idx2 = rand() % size;
        swap(&arr[idx1], &arr[idx2]);
    }
}

int main(){
    srand(time(NULL));

    list_node* head = NULL;
    tree_node* root = NULL;

    int elements, step = 10, counter = 0;
    elements = step;
    int arr[MAXLEN];

    clock_t start, end;

    while (counter++ < 1){
        generate_ascending_array(arr, elements);
        shuffle_arr(arr, elements);
        cout << elements << endl;

        // start = clock();
        // end = (double)(clock() - start) / CLOCKS_PER_SEC;
        
        // generating
        // for (int i=0; i<elements; i++){
            // insert_list_node(&head, create_list_node(arr[i]));
        // }
        for (int i=0; i<elements; i++){
            insert_tree_node(&root, create_tree_node(arr[i]));
        }

        // finding all elements
        // for (int i=0; i<elements; i++){
        //     find_list_value(head, arr[i]);
        // }
        for (int i=0; i<elements; i++){
            find_tree_value(root, arr[i]);
        }

        // deleting whole list
        // for (int i=0; i<elements; i++){
        //     delete_first_list_node(&head);
        // }
            delete_tree_postorder(&root);

        elements += step;
    }
    return 0;
}