#include <iostream>
#include <random>

#define MaxMatrixSize 5

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

void top_sort(int arr[][MaxMatrixSize], int vertex, int v, int visited[MaxMatrixSize], int sorted[MaxMatrixSize]){
    static int idx = 0;
    if (!visited[vertex]){
        visited[vertex] = 1;
        for (int col=0; col<v; col++){
            if (arr[vertex][col] && !visited[col]){
                top_sort(arr, col, v, visited, sorted);
            }
        }
        sorted[idx++] = vertex+1;
    }
}

struct node{
    int val;
    node* next;
};

void adj_matrix_to_inc_list(int arr[][MaxMatrixSize], int v, node* inc_list[MaxMatrixSize]){
    node* head;
    for (int row=0; row<v; row++){
        for (int col=0; col<v; col++){
            if (arr[row][col]){
                if (head = inc_list[row]){ // there are some nodes
                    while(head->next){
                        head = head->next;
                    }
                    head->next = new node;
                    head->next->next = NULL;
                    head->next->val = col;
                } else{
                    inc_list[row] = new node;
                    inc_list[row]->val = col;
                    inc_list[row]->next = NULL;
                }
            }
        }
    }
}