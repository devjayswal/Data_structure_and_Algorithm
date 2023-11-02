/*You are given an array a, of n elements. Find the minimum index based distance 
between two distinct elements of the array, x and y. Return -1, if either x or y does 
not exist in the array.*/
//CODE
#include<iostream>
using namespace std;

class Solution{
    public:
    int minDist(int a[], int n, int x, int y){
        int min_dist = INT_MAX;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if((x == a[i] && y == a[j] || y == a[i] && x == a[j]) && min_dist > abs(i-j)){
                    min_dist = abs(i-j);
                }
            }
        }
        if(min_dist == INT_MAX){
            return -1;
        }
        return min_dist;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i =0;i<n;i++){
            cin>>a[i];
        }
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.minDist(a,n,x,y)<<endl;
    }
    return 0;
}
