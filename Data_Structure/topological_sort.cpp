#include<bits/stdc++.h>
using namespace std;

int32_t main(){

    int n,m;
    cin>>n>>m;
    int cnt =0;;

    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int> q;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
        cnt++;
    }
    


    return 0;
}