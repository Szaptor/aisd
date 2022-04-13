#include <ctime>
#include <cstdlib>
#include "struct_def.cpp"

#define MAXARRLEN 200000

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
    tree_node* avl_root = NULL;

    int elements, step = 5000, counter = 0;
    elements = step;

    int arr[MAXARRLEN];
    vector<int> vec;

    clock_t start, end;

    cout << "-DELETING-" << endl;
    cout << "elements;list;tree" << endl;
    // cout << "elements;bst_height;avl_height" << endl;
    while (counter++ < 15){
        delete_list(&head);
        delete_tree_postorder(&root);
        cout.flush();

        generate_ascending_array(arr, elements);
        shuffle_arr(arr, elements);
        cout << elements << ";";

        // building
        
        // start = clock();
        for (int i=0; i<elements; i++){
            insert_list_node(&head, create_list_node(arr[i]));
        }
        // cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        // start = clock();
        for (int i=0; i<elements; i++){
            insert_tree_node(&root, create_tree_node(arr[i]));
        }
        // cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        // finding all elements
        
        // start = clock();
        // for (int i=0; i<elements; i++){
        //     find_list_value(head, arr[i]);
        // }
        // cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        // start = clock();
        // for (int i=0; i<elements; i++){
        //     find_tree_value(root, arr[i]);
        // }
        // cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        // deleting whole list
        start = clock();
        delete_list(&head);
        cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        start = clock();
        delete_tree_postorder(&root);
        cout << (double)(clock() - start) / CLOCKS_PER_SEC;

        // read_tree_inorder(root, &vec);
        // binary_avl_building(&avl_root, vec, 0, vec.size());
        // cout << height_of_tree(root) << ";";
        // cout << height_of_tree(avl_root);

        elements += step;
        cout << endl;
    }
    return 0;
}