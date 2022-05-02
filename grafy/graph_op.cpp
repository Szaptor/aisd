#include <iostream>
#include <ctime>
#include <algorithm>
#include "graph_def.cpp"

using namespace std;

int v = 10000;
int adj_matrix[MaxMatrixSize][MaxMatrixSize] = { 0 }; // initilize to zero
vector<int> inc_list[MaxMatrixSize];

// clock_t start;

void print_arr(int arr[][MaxMatrixSize], int v){
    for (int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// void clear_arr(int arr[][MaxMatrixSize], int v){
//     for (int i=0; i<v; i++){
//         fill(arr[i], arr[i]+v, 0);
//     }
// }

void print_vec_arr(vector<int> arr[MaxMatrixSize], int v){
    for (int i=0; i<v; i++){
        cout << i+1 << ": ";
        for (int j=0; j<arr[i].size(); j++){
            cout << arr[i][j]+1;
            if (j < arr[i].size() - 1){
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

// void clear_vec_arr(vector<int> arr[MaxMatrixSize], int v){
//     for (int i=0; i<v; i++){
//         for (int j=0; j<arr[i].size(); j++){
//             arr[j].clear();
//         }
//     }
// }

int main(){
    cout << "elements;macierz sąsiedztwa;lista incydencji" << endl;
    generate_dag(adj_matrix, v, 0.6);
    adj_matrix_to_inc_list(adj_matrix, v, inc_list);
    // print_arr(adj_matrix, v);
    // print_vec_arr(inc_list, v);

    int visited[v] = {0};
    int sorted[v];

    // sort by using adjecancy matrix
    // start = clock();
    top_sort(adj_matrix, v, visited, sorted);
    // cout << (double)(clock() - start) / CLOCKS_PER_SEC << ";";

    fill(sorted, sorted+v, 0);
    fill(visited, visited+v, 0);

    // sorting by using incidency list
    // start = clock();
    top_sort(inc_list, v, visited, sorted);
    // cout << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
}