//Given a matrix of size N x N. Print the elements of the matrix in the snake like pattern depicted below.
/*
N=3
10 20 30 40 
50 60 70 80
27 29 47 48
32 33 39 50

Output:10 20 30 40 80 70 60 50 27 29 47 48 50 39 33 32
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> snakePattern(vector<vector<int>> matrix)
{
    vector<int> ans;
    int n = matrix.size();
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                ans.push_back(matrix[i][j]);
            }
        }
    }
    return ans;
}



int main() {
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<int> ans = snakePattern(matrix);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

