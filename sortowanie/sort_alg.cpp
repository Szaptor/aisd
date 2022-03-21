#include <iostream>
using namespace std;

// features
void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

// insertion sort
void insertion_sort(int arr[], int len){
    int temp, j;
    for (int i=1; i<len; i++){
        temp = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[++j] = temp;
    }
}

// selection sort
void selection_sort(int arr[], int len){
    int max;
    for (int i=len-1; i>0; i--){
        max = i;
        for (int j=i-1; j>=0; j--){
            if (arr[max] < arr[j]){
                max = j;
            }
        }
        swap(&arr[max], &arr[i]);
    }
}

// heap sort
void heapify(int A[], int i, int heapsize){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;

    // wybranie większego z bezpośrednich potomków i-tego elementu drzewa
    if (l < heapsize && A[l] > A[largest]){
        largest = l;
    }
    if (r < heapsize && A[r] > A[largest]){
        largest = r;
    }

    if (largest != i){
        swap(&A[i], &A[largest]);
        heapify(A, largest, heapsize);
    }
}

void build_heap(int A[], int heapsize){
    // rozpoczęcie procesu od ostatniego elementu drzewa, który jest rodzicem
    for (int i=(heapsize/2)-1; i>=0; i--){
        heapify(A, i, heapsize);
    }
}

void heap_sort(int arr[], int len){
    build_heap(arr, len);
    for (int i=len-1; i>0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, 0, i);
    }
}

// merge sort
void merge_sort_main(int A[], int l, int r, int B[]){
    int m = (l + r) / 2;
    if ((m - l) > 0){
        merge_sort_main(A, l, m, B);
    }
    if ((r - m) > 1){
        merge_sort_main(A, m+1, r, B);
    }

    int i = l, j = m+1;
    for (int k=l; k<=r; k++){
        if ( (i<=m && j>r) || (i<=m && j<=r && A[i] < A[j]) ){
            B[k] = A[i++];
        } else{
            B[k] = A[j++];
        }
    }
    for (int i=0; i<=r; i++){
        A[i] = B[i];
    }
}

void merge_sort(int arr[], int len){
    int B[len];
    merge_sort_main(arr, 0, len-1, B);
}

// quick sort
void quick_sort_main(int A[], int p, int r){
    int x = A[(p+r)/2];
    int i = p-1;
    int j = r+1;
    while (true){
        do{
            j--;
        }while(A[j] > x); // szuka elementów mniejszych od pivota

        do{
            i++;
        }while(A[i] < x); // szuka elementów większych od pivota

        if (i<=j){
            swap(&A[i], &A[j]);
        } else{
            break;
        }
    }
    if (j>p){
        quick_sort_main(A, p, j);
    }
    if (i<r){
        quick_sort_main(A, i, r);
    }
    
}

void quick_sort(int arr[], int len){
    quick_sort_main(arr, 0, len-1);
}
