#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "sort_alg.cpp"

#define MAXLEN 150000

using namespace std;

int main(){
    srand(time(NULL));

    int elements, step = 10000, counter = 0;
    elements = step;
    int arr[MAXLEN], cpyarr[MAXLEN];
    while (counter++ < 15){
        int i;
        for (i=0; i<step; i++){
            arr[i] = (rand() % 30000) + 1;
        }
        arr[i] = -1; // wartość po ostatnim elemencie ujemna

        clock_t start;

        cout << "------------ ELEMENTS: " << elements << " ------------" << endl;

        copy(arr, arr+(elements-1), cpyarr);
        start = clock();
        insertion_sort(cpyarr, elements);
        cout << "Insertion sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;

        copy(arr, arr+(elements-1), cpyarr);
        start = clock();
        selection_sort(cpyarr, elements);
        cout << "Selection sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;

        copy(arr, arr+(elements-1), cpyarr);
        start = clock();
        heap_sort(cpyarr, elements);
        cout << "Heap sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;

        copy(arr, arr+(elements-1), cpyarr);
        start = clock();
        merge_sort(cpyarr, elements);
        cout << "Merge sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;

        elements += step;
    }
    return 0;
}