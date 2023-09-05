#include<bits/stdc++.h>

using namespace std;
int main(){
int r=15;
int x,y;
x=0;y=20;
int p_k = -37;
for(int i=0;i<20;i++){
    if(p_k<0){
        x = x+1;
        y=y;
        
        p_k = p_k+4*x+6;
        cout<<x<<" "<<y<<" "<<p_k<<endl;
    }
    else{
        x = x+1;
        y= y-1;
        p_k = p_k +4*(x-y)+10;
        cout<<x<<" "<<y<<" "<<p_k<<endl;
    }
}

return 0;
}