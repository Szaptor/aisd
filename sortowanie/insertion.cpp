#include <iostream>

using namespace std;

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

int main(){
    int arr[] = {5, 3, 9, 8, 1, 2, 4, 7, 6};
    int len = sizeof(arr) / sizeof(*arr);
    insertion_sort(arr, len);
    for (int i=0; i<len; i++)
        cout << arr[i] << " ";
    return 0;
}