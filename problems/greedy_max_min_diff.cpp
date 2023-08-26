#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    int max_arr_diff = 0;
    int min_arr_diff = 0;

    for(int i=0;i<n;i++){
        if(i<n/2){
            max_arr_diff -=arr[i];
        }
        else{
            max_arr_diff+=arr[i];
        }

        if(i%2==0){
            min_arr_diff-=arr[i];
        }
        else{
            min_arr_diff += arr[i];
        }
    }

    cout<<"max_arr_diff= "<<max_arr_diff<<endl<<"min_arr_diff= "<<min_arr_diff;
    
    return 0;
}