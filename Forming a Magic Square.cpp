#include <bits/stdc++.h>
using namespace std;

int cost_cal(vector<vector<int>> s, int arr[3][3]){
    int cost = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cost+=abs(s[i][j]-arr[i][j]);
        }
    }
    return cost ;
}

int minCost(vector<vector<int>> s, int arr[3][3]){
    int newarr[3][3];
    int cost = cost_cal(s,arr);

    //matrixRowSwap(arr);
    for(int i = 0 ; i < 3 ; i++)
    {
        newarr[0][i] = arr[2][i];
        newarr[2][i] = arr[0][i];
        newarr[1][i] = arr[1][i];
    }
    int temp = cost_cal(s,newarr);
    if(temp < cost )
        cost = temp;

    //matrixReverse(arr);
    for(int i = 0 ; i < 3 ; i++)
    {
        /*for(int j = 0 ; j < 3 ;j++)
        {
            newarr[i][j] = arr[i][2-j];
        }
        */
        newarr[i][0] = arr[i][2];
        newarr[i][2] = arr[i][0];
        newarr[i][1] = arr[i][1];
    }

    temp = cost_cal(s,newarr);
    if(temp < cost )
        cost = temp;

    //matrixRowSwap(arr);
    for(int i = 0 ; i < 3 ; i++)
    {
        arr[0][i] = newarr[2][i];
        arr[2][i] = newarr[0][i];
        arr[1][i] = newarr[1][i];
    }

    temp = cost_cal(s,arr);
    if(temp < cost )
        cost = temp;

    return cost ;
}

int formingMagicSquare(vector<vector<int>> s)
{
    int n=3;
    int magic[3][3];
    memset(magic,0,sizeof(magic));
    int i = n/2;
    int j = n-1;
    for(int k = 1 ; k <= n*n ; ){
        if(i<0 && j==n){
            i=0;j=n-2;
        }else if( i < 0){
            i=n-1;
        }else if(j == n){
            j = 0;
        }
        if(magic[i][j]){
            i++;
            j= j-2;
            continue; //to avoid i-- and j++
        }
        else{
           magic[i][j] = k++;
        }

        i--;
        j++;
    }

    int cost = minCost(s,magic);
    //matrixTranspose(magic);
    int newarr[3][3];
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ;j++)
        {
            newarr[i][j] = magic[j][i];
        }
    }
    int temp = minCost(s,newarr);
    if(temp < cost)
        cost = temp ;

    return cost ;

}

int main()
{

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

}
