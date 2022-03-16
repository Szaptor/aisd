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