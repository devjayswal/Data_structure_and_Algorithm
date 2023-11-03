/*Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array
 (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.*/

 #include<bits/stdc++.h>

using namespace std;

bool checkTriplet(int arr[],int n){
    vector<int> v;
    for(int i=0;i<n;i++){
        v[arr[i]]=1;
    }
    for(int i=1;i<1000;i++){
        if(v[i]){
            for(int j=1;j<1000;j++){
                if(v[j]){
                    int val=sqrt(i*i+j*j);
                    if(val*val==i*i+j*j && v[val]){
                        return true;
                    }
                }
            }
        }
        
    }
    return false;
}

int mian(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        if(checkTriplet(arr,n)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}