#include <iostream>
#include "sort_alg.cpp"

using namespace std;


int main(){
    int arr[] = {5, 3, 9, 8, 1, 2, 4, 7, 6};
    int len = sizeof(arr) / sizeof(*arr);
    selection_sort(arr, len);
    for (int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}