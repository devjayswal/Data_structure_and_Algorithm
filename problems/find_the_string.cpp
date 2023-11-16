/*Given two integers N and K, the task is to find the string S of minimum length such that
it contains all possible strings of size N as a substring.
The characters of the string should be from integers ranging from 0 to K-1. */


#include <bits/stdc++.h>

using namespace std;



        void dfs(int k , string prev ,  unordered_set<string> &seen , vector<int> &edges){
        for(int i=0 ; i<k ; i++){
            string cur = prev;
            cur+=(i+'0');
            if(seen.find(cur)==seen.end()){
                seen.insert(cur);
                dfs(k,cur.substr(1),seen,edges);
                edges.push_back(i);
            }
        }
    }

    string findString(int n, int k) {
        unordered_set<string> seen;
        string startingNode = string(n-1,'0');
        vector<int> edges;
        dfs(k,startingNode,seen,edges);
        
        string ret;
        int l = pow(k,n);
        for(int  i=0 ; i< l ; i++){
            ret+=(edges[i]+'0');
        }
        ret+=startingNode;
        return ret;
        
    }


int main(){
    int t ;
    cin>>t;

    while(t--){
        int n , k ;
        cin>>n>>k;

        string ans = cout<<findString(n,k)<<endl; 
        int ok = 1;

        for(auto i:ans){
            if(i<'0'|| i>='0'+k-1){
                ok = 0;
            }
        }
        if(!ok){
            cout<<-1<<endl;
            continue;  
        }
        unordered_set<string> seen;
        for(int i=0 ; i<=ans.size()-n+1 ; i++){
            st.insert(ans.substr(i,n));

        }
        int tot =1;
        for(int i=0 ; i<n ; i++){
            tot*=k;
        }
        if(seen.size()==tot){
            cout<<ans.size()<<endl;
            
        }else{
            cout<<-1<<endl;
        }

    }

    return 0;
}