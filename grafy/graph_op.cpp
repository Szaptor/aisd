#include <iostream>
#include "graph_def.cpp"

using namespace std;

int v = 5;
int adj_matrix[MaxMatrixSize][MaxMatrixSize] = 
{ 
   {0, 1, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {1, 0, 0, 1, 0},
   {0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0}
}; // initilize to zero


int main(){
    // create_random_arc(adj_matrix, v);
    map<int,bool> dict;
    cout << check_if_cycle(adj_matrix, v, dict) << endl;
}