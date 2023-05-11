#include <bits/stdc++.h>
using namespace std;

void bfs(int src,int n, vector<vector<int> > & adj){
        vector<int> vis(n,-1);
        vector<int> ans;
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            // cout << u <<" ";
            ans.push_back(u);
            for(int v: adj[u]){
                if(vis[v]==-1){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
}

void dfs(int src,int n, vector<vector<int> > & adj){
        vector<int> vis(n,-1);
        vector<int> ans;
        stack<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int u = q.top();
            q.pop();
            // cout << u <<" ";    
            ans.push_back(u);
            for(int v: adj[u]){
                if(vis[v]==-1){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
}
int main(){

    int n;
    cout <<"Enter number of nodes: ";
    cin>>n;
    vector<vector<int> > adj(n);

    for(int i=0;i<n;i++){
        int u,v;
        cout << "Enter  edges :  ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0,n,adj);
    dfs(0,n,adj);
    
    return 0;
}

