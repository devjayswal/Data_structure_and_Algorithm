#include<bits/stdc++.h>

using namespace std;
int main(){
int a=false;
int r=15;
int x,y;
x=0;y=15;
int p_k = -9;
for(int i=0;i<20;i++){
    if(p_k<0){
        x = x+1;
        y=y;
        
        p_k = p_k+2*x+1;
        cout<<x<<" "<<y<<" "<<p_k<<endl;
    }
    else{
        x = x+1;
        y= y-1;
        p_k = p_k -2*y+2*x+1;
        cout<<x<<" "<<y<<" "<<p_k<<endl;
    }
}

return 0;
}

