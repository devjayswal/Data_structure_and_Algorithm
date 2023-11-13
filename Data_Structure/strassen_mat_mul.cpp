#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> add(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

vector<vector<int>> subtract(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] - b[i][j];
    return c;
}

vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    if (n == 1) {
        res[0][0] = a[0][0] * b[0][0];
        return res;
    }
    int k = n / 2;
    vector<vector<int>> a11(k, vector<int>(k)), a12(k, vector<int>(k)), a21(k, vector<int>(k)), a22(k, vector<int>(k));
    vector<vector<int>> b11(k, vector<int>(k)), b12(k, vector<int>(k)), b21(k, vector<int>(k)), b22(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }
    }
    vector<vector<int>> p1 = strassen(a11, subtract(b12, b22));
    vector<vector<int>> p2 = strassen(add(a11, a12), b22);
    vector<vector<int>> p3 = strassen(add(a21, a22), b11);
    vector<vector<int>> p4 = strassen(a22, subtract(b21, b11));
    vector<vector<int>> p5 = strassen(add(a11, a22), add(b11, b22));
    vector<vector<int>> p6 = strassen(subtract(a12, a22), add(b21, b22));
    vector<vector<int>> p7 = strassen(subtract(a11, a21), add(b11, b12));
    vector<vector<int>> c11 = add(subtract(add(p5, p4), p2), p6);
    vector<vector<int>> c12 = add(p1, p2);
    vector<vector<int>> c21 = add(p3, p4);
    vector<vector<int>> c22 = subtract(subtract(add(p5, p1), p3), p7);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = c11[i][j];
            res[i][j + k] = c12[i][j];
            res[i + k][j] = c21[i][j];
            res[i + k][j + k] = c22[i][j];
        }
    }
    return res;
}

int main() {
    cout<<"Dev Jayswal"<<endl<<"0901AM221031"<<endl;
    vector<vector<int>> matrixA = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrixB = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    vector<vector<int>> result = strassen(matrixA, matrixB);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
