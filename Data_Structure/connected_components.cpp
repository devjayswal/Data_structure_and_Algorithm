//In this cod we  find  connected components in a graph 
/* algorithm:
(1) visit the node in depth first fashion.
(2) it the node is not visited , visit that node and its neighbour recursively.
(3) each time when a not visited node it found there are a connected components*/

#include<bits/stdc++.h>
using namespace std;



int get_component(int idx,vector<bool> &vis, vector<vector<int>> &adj){
    if(vis[idx]){
        return 0;
    }
    vis[idx]=true;
    int ans=1;
    for(auto i:adj[idx]){
        if(!vis[i]){
            ans+=get_component(i, vis,  adj);
            vis[i]=true;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> vis(n, false);
    vector<vector<int>> adj(n);
    
    vector<int> components;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    cout<<"connected components are"<<endl;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            
            components.push_back(get_component(i, vis, adj));
            continue;
            
    }
    }
    for(int i=0;i<components.size();i++){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;}
