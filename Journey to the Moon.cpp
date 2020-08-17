#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , p ;
    cin >> n >> p ;
    int pair_c[p][2];
    vector<int> adj[n];
    vector<int> chunk_size_list ;
    vector<int> node_list;
    int country_in_chunk = 0;
    for(int i = 0 ; i < p ; i++){
        cin >> pair_c[i][0] >> pair_c[i][1];
        adj[pair_c[i][0]].push_back(pair_c[i][1]);
        adj[pair_c[i][1]].push_back(pair_c[i][0]);
        if(!(count(node_list.begin(), node_list.end(), pair_c[i][0])))
        {
            node_list.push_back(pair_c[i][0]);
        }
        if(!(count(node_list.begin(), node_list.end(), pair_c[i][1])))
        {
            node_list.push_back(pair_c[i][1]);
        }
    }


        //bfs
        bool visited[node_list.size()];
        for(int i = 0 ; i < node_list.size() ; i++){
            visited[i] = false;
        }

        queue<int> q ;
        for(int i = 0 ; i < node_list.size() ; i++)
        {
            if(!visited[i]){
                int chunk_size = 1;
                q.push(node_list[i]);
                visited[i] = true;
                while(!q.empty()){
                    int v = q.front();
                    q.pop();

                    for(int k = 0 ; k < adj[v].size() ; k++){
                        auto it = find(node_list.begin(), node_list.end(), adj[v][k]);
                        int index = distance(node_list.begin(), it);
                        if(!visited[index]){
                            visited[index]= true;
                            q.push(adj[v][k]);
                            chunk_size++;
                        }
                    }
                }
                country_in_chunk+=chunk_size;
                //cout << "chunk size : " << chunk_size <<endl;
                chunk_size_list.push_back(chunk_size);

            }

        }

        long long countries_without_pair = n - country_in_chunk;

        long long possible_pair= 0 ;
        for(int i = 0 ; i < chunk_size_list.size()-1 ; i++){
            for(int j = i+1 ; j < chunk_size_list.size() ; j++){
                possible_pair+= chunk_size_list[i]*chunk_size_list[j];
            }
            possible_pair+= chunk_size_list[i]*countries_without_pair;
        }
        possible_pair+= chunk_size_list[chunk_size_list.size()-1]*countries_without_pair;
        possible_pair+= (countries_without_pair*(countries_without_pair-1))/2;
        cout << possible_pair << endl;



    return 0 ;
}
