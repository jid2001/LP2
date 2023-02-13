#include <bits/stdc++.h>
using namespace std;


int min_dist(vector<int> dist, vector<bool> visited){
    int min = INT_MAX, mn_idx = 0;
    for(int i = 0; i < dist.size(); i++){
        if(!visited[i] && dist[i] < min){
            mn_idx = i;
            min = dist[i];
        }
    }
    return mn_idx;
}

void sssp(vector<vector<int> > mat, int src, int v ){

    vector<int> dist(v,1e9);
    vector<bool> visited(v,0);
    dist[src] = 0;
    for(int i =0; i< v; i++){
    int u = min_dist(dist,visited);
    visited[u] = 1;
    for(int i = 0; i <v; i++){
            if(!visited[i] && mat[u][i] && dist[u] + mat[u][i] < dist[i]){
                dist[i] = dist[u] + mat[u][i];

            }
    }
    }
    cout << "Source : "<<src<<endl;
    cout << "vertex \t\t   Distance \n";
    for(int i =0; i<v; i++){
        if(visited[i])
            cout << i << "\t\t\t" << dist[i] << "\n";
    }
}
int main(){


        int v;
        cin>>v;
        vector<vector<int> > mat(v,vector<int>(v,0));
        int e ;
        cin>>e;
        for(int i =0; i<e; i++){
            int u, v, w;
            cin>>u>>v>>w;
            mat[u][v] = mat[v][u] = w;

        }

        sssp(mat,0,v);


    return 0;
}