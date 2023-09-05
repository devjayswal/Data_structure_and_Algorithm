/*You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

In the ith move, you can choose one of the following directions:

move to the left if moves[i] = 'L' or moves[i] = '_'
move to the right if moves[i] = 'R' or moves[i] = '_'
Return the distance from the origin of the furthest point you can get to after n moves.*/
//iff
#include <bits/stdc++.h>
using namespace std;

    int furthestDistanceFromOrigin(string moves) {
        int n= moves.length();
        int count =0;
        int ans=0;
        for(int i=0;i<n;i++)
        {if(moves[i]=='L'){
            count--;
        }
        else if(moves[i]=='R'){
            count++;
        }
        
        if(moves[i]=='_'){
            
           if(abs(count-1)>abs(count)){
               count--;
           }
            
            else{count++;}
        }
        
        }
        if(abs(count)>ans){
                ans=abs(count);
            }
        
        return ans;
    }


int main(){
    string s;
    cin>>s;

    int ans = furthestDistanceFromOrigin(s);

    cout<<"the maximum possible distance is = "<<ans<<endl; 

}