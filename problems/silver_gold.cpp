/*There are N coins kept in a line. Each coin has two sides - one is colored gold and the other silver. You can flip two adjacent coins any number of times. You need to make the gold-colored side of every coin facing up. You are given the initial status of coins in a binary string s where '1' represents the gold side facing up and '0' represents the silver side facing up. If it is possible to make the gold-colored side of every coin facing up, return "Yes", otherwise return "No"*/

#include <bits/stdc++.h>

using namespace std;

string flipCoins(int N , string S){
    int count = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == '0'){
            count++;
        }
    }
    if(count % 2 == 0){
        return "Yes";
    }
    return "No";
}

int main(){
    int N;
    string S;
    cin >> N >> S;
    cout << flipCoins(N, S) << endl;
    return 0;
    
}