#include <iostream>
#include "sort_alg.cpp"

using namespace std;

int main(){
    int arr[] = {1, 2, 8, 9, 5};
    int len = sizeof(arr) / sizeof(*arr);
    quick_sort(arr, len);
    for (int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}