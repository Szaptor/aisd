#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "sort_alg.cpp"

#define MAXLEN 150000

using namespace std;

enum generation_mode {RANDOM, ASCENDING, DESCENDING, VSHAPED};

void generate_array(int arr[], int len, generation_mode mode){ // negative value after last element
    int i, j;

    switch(mode){
        case RANDOM:
            for (i=0; i<len; i++){
                arr[i] = (rand() % 30000) + 1;
            }
            arr[i] = -1;
            break;
        case ASCENDING:
            for (i=0; i<len; i++){
                arr[i] = i + 1;
            }
            arr[i] = -1;
            break;
        case DESCENDING:
            j = len;
            for (i=0; i<len; i++){
                arr[i] = j--;
            }
            arr[i] = -1;
            break;
        case VSHAPED:
            j = len/2;
            for (i=0; i<len/2; i++){
                arr[i] = j--;
            }
            for (i=len/2; i<len; i++){
                arr[i] = j++;
            }
            arr[i] = -1;
    }
    
}

int main(){
    srand(time(NULL));

    int elements, step = 10000, counter = 0;
    elements = step;
    int arr[MAXLEN], cpyarr[MAXLEN];
    clock_t start;

    cout << "\"Liczba elementow\";\"Insertion sort\";\"Selection sort\";\"Heap sort\";\"Merge sort\"" << endl;

    while (counter++ < 15){
        generate_array(arr, elements, DESCENDING);

        cout << elements << ";";

        copy(arr, arr+elements, cpyarr);
        start = clock();
        insertion_sort(cpyarr, elements);
        cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        copy(arr, arr+elements, cpyarr);
        start = clock();
        selection_sort(cpyarr, elements);
        cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        copy(arr, arr+elements, cpyarr);
        start = clock();
        heap_sort(cpyarr, elements);
        cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

        copy(arr, arr+elements, cpyarr);
        start = clock();
        merge_sort(cpyarr, elements);
        cout << (double)(clock() - start) / CLOCKS_PER_SEC << endl;

        elements += step;
    }
    return 0;
}