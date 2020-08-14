#include <bits/stdc++.h>

using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> rank_alice;
    int k = 0;
    int rank = 1;
    for(int i = alice.size()-1 ; i >=0 ; i--){
        rank = (scores[k] <= alice[i])? rank: (rank+1) ;
        int prev = scores[k];
        while(alice[i] < scores[k] && k < scores.size()){
                //cout << "k  "<< k << endl;
            if(prev > scores[k]){
                rank++;prev = scores[k];
            }
            //cout << " *** " <<alice[i] << "   " << scores[k] << "   " << rank << endl;
            k++;
        }
        rank_alice.push_back(rank);
    }
    reverse(rank_alice.begin(),rank_alice.end());
    return rank_alice;

}

int main()
{
    int n , m , value;
    cin >> n ;
    vector<int> scores;
    for(int i = 0 ; i < n ; i++){
        cin >> value;
        scores.push_back(value);
    }
    cin >> m ;
    vector<int> alice;
    for(int i = 0 ; i < m ; i++){
        cin >> value;
        alice.push_back(value);
    }

    vector<int> alice_rank = climbingLeaderboard(scores,alice);
    for(int i = 0 ; i < m ; i++){
        cout << alice_rank[i] << "  ";
    }
    cout << endl;
    return 0 ;
}
