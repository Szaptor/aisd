#include <iostream>
#include <cstdlib>
#include <map>

#define MaxMatrixSize 5

using namespace std;

// not working
bool check_if_cycle(int arr[][MaxMatrixSize], int v, map<int, bool> visited, int row=0){
    for (int i=0; i<v; i++){
        if (arr[row][i]){
            if (visited[i]){
                return true;
            } else{
                visited[row] = true;
            }

            if (check_if_cycle(arr, v, visited, i)){
                return true;
            }
        }
    }
    return false;
}

void create_random_arc(int arr[][MaxMatrixSize], int v){
    srand(time(NULL));
    int x=-1, y;

    do{
        if(x>=0){
            arr[x][y] = 0;
        }
        do{
            x = rand() % v;
            y = rand() % v;
        }while(!arr[x][y] && y!=x);
        arr[x][y] = 1;
    }while(false);
    
    arr[x][y] = 1;
}