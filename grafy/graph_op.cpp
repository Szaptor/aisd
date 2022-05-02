#include <iostream>
#include "graph_def.cpp"

using namespace std;

int v = 5;
int adj_matrix[MaxMatrixSize][MaxMatrixSize] = { 0 }; // initilize to zero
node* inc_list[MaxMatrixSize] = {NULL};

void print_arr(int arr[][MaxMatrixSize], int v){
    for (int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    generate_dag(adj_matrix, v, 0.4);
    print_arr(adj_matrix, v);

    int visited[v] = {0};
    int sorted[v];
    for (int i=0; i<v; i++)
        top_sort(adj_matrix, i, v, visited, sorted);

    adj_matrix_to_inc_list(adj_matrix, v, inc_list);
}