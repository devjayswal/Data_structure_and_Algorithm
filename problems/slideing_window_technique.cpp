#include <bits/stdc++.h>
#include <iostream>
#define vi vector<int>
#define vii pair<int,int>
#define pii vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) __builtin_popcount(x)

using namespace std;
signed main(){
    int n, k ;
    cin>>n>>k;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int s =0, ans = INT_MAX;
    rep(i,0,k){
        s+=a[i];
        }
    cout<<s<<" ";

    ans = min(ans,s);
    
    // Sliding Window technque  has been started from here;


    rep( i , 1, n-k+1){
      s-=a[i-1];
      s+=a[i+k-1];
      ans= min(ans,s );

    cout<<s<<" ";
    }
    cout<<endl;

cout<<ans<<endl;
return 0;

}