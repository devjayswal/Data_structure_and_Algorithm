#include <bits/stdc++.h>
#include <iostream>
#define vi vector<int>
#define vii pair<int,int>
#define pii vector<int>
#define rep(i,a,b)for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) __builtin_popcount(x)

using namespace std;

signed main(){
    int n;
    cout<<"enter the number of elements";
    
    cin >> n;
    vi a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    map <int , int > freq;
    rep(i,0,n){
        freq[a[i]]++;
    }
    map <int, int > :: iterator it;
    for ( it=freq.begin(); it!= freq.end(); it++){
        
        cout<< it ->ff<<" "<<it-> ss<<endl;

    }

}