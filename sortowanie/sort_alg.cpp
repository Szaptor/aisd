void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

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