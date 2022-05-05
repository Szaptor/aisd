#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#define MaxMatrixSize 10
using namespace std;
//tutaj robiê listê z tablicy dziêki mojemu dobremu koledze Bartkowi

void adj_matrix_to_inc_list(int arr[][MaxMatrixSize], int v, vector<pair<int, int>> inc_list[MaxMatrixSize]){
    pair <int, int> temp_pair;
    for (int row=0; row<v; row++){
        for (int col=0; col<v; col++){
            if (arr[row][col]){
                temp_pair.first = col;
                temp_pair.second = arr[row][col];
                inc_list[row].push_back(temp_pair);
            }
        }
    }
}
void print_vec_arr(vector<pair<int, int>> arr[MaxMatrixSize], int v){
    for (int i=0; i<v; i++){
        cout << i+1 << ": ";
        for (int j=0; j<arr[i].size(); j++){
            cout << "(" << arr[i][j].first + 1 << ", " << arr[i][j].second << ")";
            if (j < arr[i].size() - 1){
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

int main()
{
    srand( time( NULL ) );
    int n=5;
    for(int i=0;i<2;i++)
    {
        int  maxi=((n-1)*n)/2, trzy=maxi*0.3 -n-1, siedem=maxi*0.7 -n-1;
        int tab[MaxMatrixSize][MaxMatrixSize];
        vector<pair<int, int>> inc_list[MaxMatrixSize];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                tab[i][j]=0;
        //cout<<"n: "<<n<<" maxi: "<<maxi<<" 30%: "<<trzy<<" 70%: "<<siedem<<endl;

        //szkielet
        for(int i=0;i<n-1;i++)
        {
            int temp=rand()%1000+1;
            tab[i][i+1]=temp;
            tab[i+1][i]=temp;
        }

        //30%
        cout<<"30%"<<endl;
        for(int g=0;g<trzy;g++)
        {
            int i=rand()%n+0;
            int j=rand()%n+0;
            if((i==j)||(tab[i][j]!=0))
            {
                g--;
                continue;
            }
            int temp=rand()%1000+1;
            tab[i][j]=temp;
            tab[j][i]=temp;
        }
        //wyswietlanie
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<tab[i][j]<<" ";
            cout<<endl;
        }
        //70%
        /*
        cout<<"70%"<<endl;
        for(int g=0;g<siedem;g++)
        {
            int i=rand()%n+0;
            int j=rand()%n+0;
            if((i==j)||(tab[i][j]!=0))
            {
                g--;
                continue;
            }
            int temp=rand()%1000+1;
            tab[i][j]=temp;
            tab[j][i]=temp;
        }
        */
        //zamiana

        adj_matrix_to_inc_list(tab, n, inc_list);
        print_vec_arr(inc_list, n);
        //prima
        cout<<"Pierwsza proba"<<endl;
        bool wierzcholki[n]={false};
        wierzcholki[0]=true;
        pair<int,int> krawedzie[n-1];
        int min_i, minj,suma=0;
        for(int g=0;g<(n-1);g++) //petla aby znalezc
        {
            int mini=1001; //bo maksymalna waga to 1000 wiec zawsze bedzie cos mniejszego
            for(int i=0;i<n;i++)
            {
                if(!wierzcholki[i]) //pomijam nienalezace wierzcholki
                    continue;
                for(int j=0;j<n;j++)
                {
                    if(wierzcholki[j]) //pomijam nalezace wierzcholki (skoro juz naleza to po co szukac do nich polaczen)
                        continue;
                    if((mini>tab[i][j])&&(tab[i][j]!=0))
                    {
                        mini=tab[i][j];
                        min_i=i;
                        minj=j;
                    }
                }
            }
            wierzcholki[minj]=true;
            suma=suma+tab[min_i][minj];
            krawedzie[g].first=min_i;
            krawedzie[g].second=minj;
        }
        for(int i=0;i<n-1;i++)
            cout<<"("<<krawedzie[i].first<<","<<krawedzie[i].second<<")"<<endl;
        cout<<suma<<endl;

        cout<<"Druga proba"<<endl;
        //lista TV
        bool wierzcholki1[n]={false};
        wierzcholki1[0]=true;
        //lista T
        pair<int,int> krawedzie1[n-1];
        int T=0, min_i1, min_j1;
        while(T<n-1)
        {
            int mini1=1001;
            //dopisywanie krawedzi
            for(int i=0;i<n;i++)
            {
                if(!wierzcholki1[i])
                    continue;
                for(int j=0;j<n;j++)
                {
                    if(wierzcholki1[j])
                        continue;
                    if((mini1>tab[i][j])&&(tab[i][j]!=0))
                    {
                        mini1=tab[i][j];
                        min_i1=i;
                        min_j1=j;
                    }

                }
            }
            wierzcholki1[min_j1]=true;
            krawedzie1[T].first=min_i1;
            krawedzie1[T].second=min_j1;
            T++;
        }
        for(int i=0;i<T;i++)
            cout<<"("<<krawedzie1[i].first<<","<<krawedzie1[i].second<<")"<<endl;
        cout<<"Lista"<<endl;
        //prim dla listy
        //lista TV
        bool wierzcholki_l[n]={false};
        wierzcholki_l[0]=true;
        //lista T
        pair<int,int> krawedzie_l[n-1];
        int T_l=0, min_i_l, min_j_l;
        while(T_l<n-1)
        {
            int mini_l=1001;

            for(int i=0;i<n;i++)
            {
                if(!wierzcholki_l[i])
                    continue;
                for(int j=0;j<inc_list[i].size();j++)
                {
                    if(wierzcholki_l[inc_list[i][j].first])
                        continue;
                    if(mini_l>inc_list[i][j].second)
                    {
                        mini_l=inc_list[i][j].second;
                        min_i_l=i;
                        min_j_l=j;
                    }
                }
            }
            wierzcholki_l[inc_list[min_i_l][min_j_l].first]=true;
            krawedzie_l[T_l].first=min_i_l;
            krawedzie_l[T_l].second=inc_list[min_i_l][min_j_l].first;
            T_l++;
        }
        for(int i=0;i<T_l;i++)
            cout<<"("<<krawedzie_l[i].first<<","<<krawedzie_l[i].second<<")"<<endl;
        n=n+5;
    }
    return 0;
}
