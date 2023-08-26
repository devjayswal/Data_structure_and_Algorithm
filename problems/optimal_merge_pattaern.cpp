/*you are given n files with their  computation times in an araay 
operation:- choose/take  any two files , add their computation times and append it to the list of computation time 
cost= sum of computation*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cout << "Enter the number of files : ";
    int n;
    cin >> n;
    vector<int> a(n);

    cout << "Enter the computation time of each file : ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++){
        minHeap.push(a[i]);
    }
    int ans = 0;
    while(minHeap.size() > 1){
        int e1 = minHeap.top();
        minHeap.pop();
        int e2 = minHeap.top();
        minHeap.pop();
        ans += e1 + e2;
        minHeap.push(e1 + e2);
    }
    cout << "Minimum cost of merging is : ";
    cout << ans << endl;
    return 0;





}