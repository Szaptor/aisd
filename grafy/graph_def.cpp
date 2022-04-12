#include <iostream>
#include <cstdlib>

#define MaxMatrixSize 10000

using namespace std;

void create_random_arc(int arr[][MaxMatrixSize], int v){
    srand(time(NULL));
    int x, y;

    do{
        x = rand() % v;
        y = rand() % v;
    }while(!arr[x][y]);
    arr[x][y] = 1;
}