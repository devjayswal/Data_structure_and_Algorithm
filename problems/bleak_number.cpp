//"A number n is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x."
#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    cout<<count<<endl;
    return count;
}



int isBleak(int n){
    int bits = countSetBits(n);
    if(n-bits<0)
        return 1;
    return 0;
}

int main(){
    int n;
    cin>>n;
    cout<<isBleak(n);
    return 0;
}