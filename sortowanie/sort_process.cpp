#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "sort_alg.cpp"

#define MAXLEN 200000

using namespace std;

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
            j = len/2;
            for (i=0; i<len/2; i++){
                arr[i] = j--;
            }
            for (i=len/2; i<len; i++){
                arr[i] = j++;
            }
            break;
        case ASHAPED:
            j = 0;
            for (i=0; i<len/2; i++){
                arr[i] = j++;
            }
            for (i=len/2; i<len; i++){
                arr[i] = j--;
            }
            break;
        case CONSTANT:
            for (i=0; i<len; i++){
                arr[i] = 1;
            }
            break;
    }  
}

double measure_time(int arr[], int elements, int cpyarr[], void (*sort_func)(int[], int)){
        clock_t start;
        copy(arr, arr+elements, cpyarr);
        start = clock();
        sort_func(cpyarr, elements);
        return (double)(clock() - start) / CLOCKS_PER_SEC;
}

int main(){
    srand(time(NULL));
// clock_t start;
    int elements, step = 10000, counter = 0;
    elements = step;
    int arr[MAXLEN], cpyarr[MAXLEN];

    cout << "\"Liczba elementow\";\"Insertion sort\";\"Selection sort\";\"Heap sort\";\"Merge sort\"" << endl;

    while (counter++ < 15){
        generate_array(arr, elements, CONSTANT);
        cout << endl;
        cout << elements << ";";

        cout << measure_time(arr, elements, cpyarr, &insertion_sort) << ";";

        cout << measure_time(arr, elements, cpyarr, &selection_sort) << ";";

        cout << measure_time(arr, elements, cpyarr, &heap_sort) << ";";

        cout << measure_time(arr, elements, cpyarr, &merge_sort) << ";";

        // cout << measure_time(arr, elements, cpyarr, &quick_sort) << endl;

        elements += step;
    }
    return 0;
}