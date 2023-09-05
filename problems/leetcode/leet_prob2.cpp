/*You are given positive integers n and target.

An array nums is beautiful if it meets the following conditions:

nums.length == n.
nums consists of pairwise distinct positive integers.
There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
Return the minimum possible sum that a beautiful array could have.*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        if(n==1){
            return 1;
        }
        int size =n-1;
        int arr[n];
        int num=2;
        arr[0]=1;
        int i=0;
        while(size>0){
            
            if((arr[i]+num)!=target){
               
                if(arr[i-1]!=num&&i>0){
                    arr[i]=num;
                    size--;
                    num++;
                    i++;
                }else{
                    num++;
                    
                }
            }
            
        }
        int sum=0;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        return sum;
    }
};