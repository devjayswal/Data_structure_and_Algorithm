#include<bits/stdc++.h>

using namespace std;

void helper(int r,int c,vector<vector<char>>& a,map<pair<int,int>,map<int, int >>& mp,vector<map<int,int>>& row,vector<map<int,int>>& col){
        if(r==9){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }
        int i=r,j=c;
        if(j==9){
                helper(i+1,0,a,mp,row,col);
                return;
            }
        if(a[r][c]!='.'){
                helper(r,c+1,a,mp,row,col);
                return;
        }
        
            for(int k=1;k<=9;k++){
                int rw=r/3,cl=c/3;
                if(mp[{rw,cl}][k]==0 && row[i][k]==0 && col[j][k]==0){
                    mp[{rw,cl}][k]=1;
                    row[i][k]=1;
                    col[j][k]=1;
                    a[i][j]=k+'0';


                    if(j==8){
                        helper(i+1,0,a,mp,row,col);
                    }
                    else{
                        helper(i,j+1,a,mp,row,col);
                    }
                    mp[{i/3,j/3}][k]=0;
                    row[i][k]=0;
                    col[j][k]=0;
                    a[i][j]='.';
                }
            }
        
    }


void solveSudoku(vector<vector<char>>& board) {
        map<pair<int,int>,map<int, int >> mp;
        vector<map<int,int>> row(9);
        vector<map<int,int>> col(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    mp[{i/3,j/3}][board[i][j]-'0']=1;
                    row[i][board[i][j]- '0']=1;
                    col[j][board[i][j]- '0']=1;

                }
            }
        }
        helper(0,0,board,mp,row,col);


    }

int main(){
    vector<vector<char>> a(9,vector<char>(9));a={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}


    };

    
    solveSudoku(a);



    return 0;
}