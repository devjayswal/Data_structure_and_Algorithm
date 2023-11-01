#include<iostream>
#include<string>
using namespace std;

string tobinary(int n) {
    string binary = "";
    while (n > 0) {
        int last_bit = n & 1;
        binary = to_string(last_bit) + binary;
        n >>= 1;
    }
    return binary;
}

bool checkKthBit(int n, int k) {
    string binary = tobinary(n);
    if (k >= 0 && k < binary.length() && binary[binary.length() - 1 - k] == '1') {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << checkKthBit(n, k) << endl;
}
