#include <iostream>
#include "graph_def.cpp"

using namespace std;

int v = 10;
int adj_matrix[MaxMatrixSize][MaxMatrixSize] = { 0 }; // initilize to zero

int main(){
    
    adj_matrix[1][2] = 15;
    create_random_arc(adj_matrix, v);
}