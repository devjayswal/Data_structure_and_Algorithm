#include<bits/stdc++.h>
#include<algorithm>
#include<string.h>
using namespace std;

string replaceUnderscores( string input, char replacement) {
    string result = input; 
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == '_') {
            result[i] = replacement;
        }
    }
    
    return result;
}


int findfurtherestpoint(string moves){
    int count=0;
    int ans=0;
    int n = moves.size();
    char L=0,R=0;
    int total=0;
    for(int i=0;i<n;i++){
        if(moves[i]=='L'){
            L++;
        }
        if(moves[i]=='R'){
            R++;
        }}
        
    if(L>R){
        total='L';
    }else{total='R';}
    
     moves =  replaceUnderscores(moves,total);
     
     
     for(int i=0;i<n;i++){
        if(moves[i]=='L'){
            count--;
        }
        if(moves[i]=='R'){
            count++;
        }}
       
    ans = abs(count);
    
    return ans;
};

int main()
{
    string a;
    cin>>a;
   int ans=findfurtherestpoint(a);
    
    cout<<ans<<endl;
    
    return 0;
    
    }