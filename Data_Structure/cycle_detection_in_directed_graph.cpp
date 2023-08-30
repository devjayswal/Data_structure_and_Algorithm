//this code is for cycle detection in undirected graph using dfs
//time complexity O(V+E)

#include<bits/stdc++.h>


using namespace std;

bool iscycle(int src, vector<vector<int>> &adj, vector<bool>&visited, vector<int> &stack1){
    stack1[src]=true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i:adj[src]){
            if(!visited[i] and iscycle(i,adj,visited,stack1)){
                return true;
            }
            else if(stack1[i]){
                return true;
            }
        }
    }
    stack1[src]=false;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector < int >> adj(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    bool cycle=false;
    vector<int> stack1(n,0);
    vector<bool> visited(n,false);


    for(int i=0;i<n;i++){
        if(!visited[i] and iscycle(i,adj,visited,stack1)){
            cycle=true;
            break;
        } 
    }
    
    if(cycle){
        cout<<"cycle is present";
    }
    else{
        cout<<"cycle is not present";}

    return 0;
    }