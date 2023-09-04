/*
there are three tower  in one two there are  few block of few size
 you need to move all block from one tower to third tower in same order
*/

#include<bits/stdc++.h>

using namespace std;

void towerofhonoi(int n,char src,char dest,char helper){
    if(n==0){
        return;
    }
    towerofhonoi(n-1,src,helper,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofhonoi(n-1,helper,dest,src);
}

int main(){
    int n;
    cin>>n;
    towerofhonoi(n,'A','C','B');
    return 0;
}