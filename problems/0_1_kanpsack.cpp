#include<iostream>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)

const int N = 1e3+2,mod = 1e9+7;
int dp[N][N];

int val[N], wt[N];

int kanpsack(int n, int w){
    if(n<=0 || w<=0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(wt[n-1]>w){
        return dp[n][w] = kanpsack(n-1, w);
    }
    else{
        return dp[n][w] = max(kanpsack(n-1, w), val[n-1]+kanpsack(n-1, w-wt[n-1]));
    }
    return dp[n][w];
}

int main(){
    cout<<"Dev Jayswal"<<endl<<"0901AM221031"<<endl;
    int n ; cin>>n;

    rep(i, 0, n){
        cin>>val[i];
    }
    rep(i, 0, n){
        cin>>wt[i];
    }

    rep(i, 0, N){
        rep(j, 0, N){
            dp[i][j] = -1;
        }
    }
    int W; cin>>W;

    cout<<kanpsack(n, W)<<endl;
}