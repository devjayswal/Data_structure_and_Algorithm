//cycle detection in undirected graph 
#include<bits/stdc++.h>
using namespace std;


bool iscycle( int src, vector<vector<int>> &adj, vector<bool> &vis, int parent){
    vis[src] = true;
    for(auto i : adj[src]){
        if(i!=parent){
            if(vis[i]){
                return true;
            }
            if(!vis[i] and iscycle(i,adj,vis,src)){
                return true;
            }
        }
    }
    return false;
}

int32_t main(){

    int n,m; 
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle =false;
    vector<bool> vis(n,false);
    for(int i =0;i<n;i++){
        if(!vis[i] and iscycle(i,adj,vis,-1)){
            cycle = true;
        }
    }
    if(cycle){
        cout<<"cycle is present";
    }
    else{
        cout<<"cycle is not present";
    }



}