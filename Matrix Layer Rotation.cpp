#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void matrixRotation(vector<vector<int>> matrix, int r) {

    int m =matrix.size(), M= matrix.size();
    int n =matrix[0].size() , N= matrix[0].size();
    int newmatrix[m][n];

    int layer;
    if(m<n){
        layer = m/2;
        if(m%2!=0)layer++;
    }else{
        layer = n/2;
        if(n%2!=0)layer++;
    }

    for(int i = 0 ; i < layer ; i++){
        m = M - i*2;
        n = N - i*2 ;
        int max_rotation = (m*2)+(n-2)*2;
        int rotation = r % max_rotation ;
        // prev = [i][i]
        int new_i;
        int new_j;
        if(rotation <= m-1){
            new_i = i+rotation;
            new_j = i ;
        }else if(rotation <=(m-1+n-1)){
            new_i = m-1+i ;
            new_j = rotation - (m-1)+i;
        }else if(rotation <=(m-1+n-1+m-1)){
            new_i = M-1-(rotation - (m-1+n-1)+i);
            new_j = n-1+i;
        }else{
            new_i = i ;
            new_j = max_rotation - rotation +i;
        }

        newmatrix[new_i][new_j] = matrix[i][i];
        int previ = i;
        int prevj = i;
        for(int k = 1 ; k < max_rotation ; k++){

            if(new_j == i && new_i < (i+m-1) )
                new_i++;
            else if(new_i == (m-1+i) && new_j < (n-1+i))
                new_j++;
            else if(new_j == (n-1+i) && new_i >(i))
                new_i--;
            else if(new_i == i)
                new_j--;

            if(k<=m-1) previ++;
            else if(k <= (m-1+n-1))prevj++;
            else if(k <= (m-1+n-1+m-1))previ--;
            else prevj--;

            //cout << previ << ","<< prevj << "  " << new_i  << ","<< new_j << endl;
            newmatrix[new_i][new_j] = matrix[previ][prevj];
        }

    }
     for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cout  << newmatrix[i][j] << " " ;
        }
        cout << endl;
    }
}

int main()
{
    int m , n , r  ;
    cin >> m >> n >> r;
    vector<vector<int>> matrix(m);
    for(int i = 0 ; i < m ; i++){
        matrix[i].resize(n);
        for(int j = 0 ; j < n ; j++){
            cin >> matrix[i][j] ;
        }
    }

    matrixRotation(matrix,r);

    return 0 ;
}
