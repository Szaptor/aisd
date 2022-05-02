#include <iostream>
#include <random>
#include <vector>

#define MaxMatrixSize 100000

using namespace std;


void generate_dag(int arr[][MaxMatrixSize], int v, float saturation){
    int row, col;
    // to generate random value from range
    random_device rd;
    mt19937 gen(rd());

    for (int i=0; i<(v*(v-1)/2)*saturation; i++){
        row = i % (v-1);

        uniform_int_distribution<> col_range(row+1, v-1);
        col = col_range(gen);

        arr[row][col] = 1;
    }
}

void adj_matrix_to_inc_list(int arr[][MaxMatrixSize], int v, vector<int> inc_list[MaxMatrixSize]){
    for (int row=0; row<v; row++){
        for (int col=0; col<v; col++){
            if (arr[row][col]){
                inc_list[row].push_back(col);
            }
        }
    }
}

void top_sort_main(int arr[][MaxMatrixSize], int vertex, int v, int visited[MaxMatrixSize], int sorted[MaxMatrixSize]){
    static int idx = 0;
    if (!visited[vertex]){
        visited[vertex] = 1;
        for (int col=0; col<v; col++){
            if (arr[vertex][col] && !visited[col]){
                top_sort_main(arr, col, v, visited, sorted);
            }
        }
        sorted[idx++] = vertex+1;
    }
}

void top_sort_main(vector<int> arr[MaxMatrixSize], int vertex, int v, int visited[MaxMatrixSize], int sorted[MaxMatrixSize]){
    static int idx = 0;
    if (!visited[vertex]){
        visited[vertex] = 1;
        for (int i=0; i<arr[vertex].size(); i++){
            int next_node = arr[vertex][i];
            if (!visited[next_node]){
                top_sort_main(arr, next_node, v, visited, sorted);
            }
        }
        sorted[idx++] = vertex+1;
    }
}

void top_sort(vector<int> arr[MaxMatrixSize], int v, int visited[MaxMatrixSize], int sorted[MaxMatrixSize]){
    for (int i=0; i<v; i++){
        if (sorted[v-1]){
            break;
        }
        top_sort_main(arr, i, v, visited, sorted);
    }
}

void top_sort(int arr[][MaxMatrixSize], int v, int visited[MaxMatrixSize], int sorted[MaxMatrixSize]){
    for (int i=0; i<v; i++){
        if (sorted[v-1]){
            break;
        }
        top_sort_main(arr, i, v, visited, sorted);
    }
}
