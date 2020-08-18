
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int qu ;
    cin >> qu ;
    for(int q = 0 ; q < qu ; q++){
        int m , n ;
        cin >> m >> n ;
        priority_queue <long long> q_y;
        priority_queue <long long> q_x;
        long long cost_y[m-1];
        long long cost_x[n-1];

        for( int i = 0 ; i < m-1 ; i++){
            cin >> cost_y[i];
            q_y.push(cost_y[i]);
        }
        for( int i = 0 ; i < n-1 ; i++){
            cin >> cost_x[i];
            q_x.push(cost_x[i]);
        }
        int row_cut = 1 ;
        int col_cut = 1 ;
        long long cost = 0;

        while(!q_y.empty() && !q_x.empty()){
            if(q_y.top() >= q_x.top()){
                cost += q_y.top()*col_cut;
                row_cut++;
                q_y.pop();
            }else{
                cost += q_x.top()*row_cut;
                col_cut++;
                q_x.pop();
            }
        }
        while(!q_y.empty()){
            cost += q_y.top()*col_cut;
            row_cut++;
            q_y.pop();
        }
        while(!q_x.empty()){
            cost += q_x.top()*row_cut;
            col_cut++;
            q_x.pop();
        }
        cost = cost % 1000000007;
        cout << cost << endl;
    }
    return 0 ;
}

