#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;

#define int long long
#define N 102
#define Mod 1000000007
 int arr[N];
 int dp[N][N];

 int mcm(int i, int j){
     if(i>=j){
         return 0;
     }
     if(dp[i][j]!=-1){
         return dp[i][j];
     }
     int ans = INT_MAX;
     for(int k=i; k<j; k++){
         int temp = mcm(i, k) + mcm(k+1, j) + arr[i-1]*arr[k]*arr[j];
         ans = min(ans, temp);
     }
     return dp[i][j] = ans;
 }


signed main(){
    cout<<"Dev Jayswal"<<endl<<"0901AM221031"<<endl;
    int n ;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }

    cout<<mcm(1, n-1)<<endl;

    return 0;
}