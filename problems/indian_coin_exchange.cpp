/*problem  you are given n coins of different denominations and a total amount of money amount.
write a program to calculate minimum number of coins that you need to make up that amount.
*/



#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first   
#define ss second
#define setBits(x) builtin_popcount(x)

signed main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    int x;
    cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += x / a[i];
        x -= x / a[i] * a[i];
    }

    cout << ans << endl;
    return 0;
}