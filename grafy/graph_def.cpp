#include <iostream>
#include <random>

#define MaxMatrixSize 5

using namespace std;


void generate_dag(int arr[][MaxMatrixSize], int v, float nasycenie){
    int row, col;
    // to generate random value from range
    random_device rd;
    mt19937 gen(rd());

    for (int i=0; i<(v*(v-1)/2)*nasycenie; i++){
        row = i % (v-1);

        uniform_int_distribution<> col_range(row+1, v-1);
        col = col_range(gen);

        arr[row][col] = 1;
    }
}

void top_sort(int arr[][MaxMatrixSize], int vertex, int v, int visited[MaxMatrixSize], int sorted[MaxMatrixSize]){
    static int idx = 0;
    if (!visited[vertex]){
        visited[vertex] = 1;
        for (int col=0; col<v; col++){
            if (arr[vertex][col] && !visited[col]){
                top_sort(arr, col, v, visited, sorted);
            }
        }
        // cout << "idx: " << idx << " | ";
        sorted[idx++] = vertex+1;
    }
}