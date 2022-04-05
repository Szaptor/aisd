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
    int elements, step = 1000, counter = 0;
    elements = step;
    int arr[MAXLEN];

    while (counter++ < 15){
        generate_ascending_array(arr, elements);
        shuffle_arr(arr, elements);
        cout << elements << endl;

        // generating list
        for (int i=0; i<elements; i++){
            insert_node(&head, create_node(arr[i]));
        }

        // finding all elements
        for (int i=0; i<elements; i++){
            find_value(head, arr[i]);
        }

        // deleting whole list
        for (int i=0; i<elements; i++){
            delete_first_node(&head);
        }

        elements += step;
    }
    return 0;
}