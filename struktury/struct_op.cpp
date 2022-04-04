#include <iostream>
#include <ctime>
#include <cstdlib>
#include "struct_def.cpp"

using namespace std;

void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

enum generation_mode {RANDOM, ASCENDING, DESCENDING, VSHAPED, ASHAPED, CONSTANT};

void generate_array(int arr[], int len, generation_mode mode){
    int i, j;

    switch(mode){
        case RANDOM:
            for (i=0; i<len; i++){
                arr[i] = (rand() % 30000) + 1;
            }
            break;
        case ASCENDING:
            for (i=0; i<len; i++){
                arr[i] = i + 1;
            }
            break;
        case DESCENDING:
            j = len;
            for (i=0; i<len; i++){
                arr[i] = j--;
            }
            break;
        case VSHAPED:
            j = 2*(len/2);
            for (i=0; i<len/2; i++){
                arr[i] = j;
                j -= 2;
            }
            j+=1;
            for (i=len/2; i<len; i++){
                j += 2;
                arr[i] = j;
            }
            break;
        case ASHAPED:
            j = 0;
            for (i=0; i<len/2; i++){
                arr[i] = j;
                j += 2;
            }
            j -= 1;
            for (i=len/2; i<len; i++){
                arr[i] = j;
                j -= 2;
            }
            break;
        case CONSTANT:
            for (i=0; i<len; i++){
                arr[i] = 1;
            }
            break;
    }
}

void shuffle_arr(int arr[], int size){
    for (int i=0; i<size*2; i++){
        int idx1 = rand() % size;
        int idx2 = rand() % size;
        swap(&arr[idx1], &arr[idx2]);
    }
}

int main(){
    srand(time(NULL));
    list_node* head = NULL;
    // to fix
    insert_node(&head, create_node(4));
    insert_node(&head, create_node(5));
    insert_node(&head, create_node(12));
    print_list(head);
    return 0;
}