#include<bits/stdc++.h>
using namespace std;

//Brute approach 
bool isPossible(int row,int col,vector<string> &board,int n){

        int drow=row,dcol=col;
        //checking upper left diagnol
        while(drow>=0 && dcol>=0){
            if(board[drow][dcol]=='Q') return false;
            row--;
            col--;
            
        }

        drow=row;
        dcol=col;
        //checking left 
        while(dcol>=0){
            if(board[drow][dcol]=='Q') return false;
            col--;
            
        }

        drow=row;
        dcol=col;
        //checking lower left diagnol 
        while(drow<n && dcol>=0){
            if(board[drow][dcol]=='Q') return false;
            row++;
            col--;
            
        }

        return true;
    }
    void NQueens(int col,vector<vector<string>> &ans,vector<string> &board,int n){

        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isPossible(row,col,board,n)){
                board[row][col]='Q';
                NQueens(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>board(n);
        string str(n,'.');
        for(int i=0;i<n;i++){
            board[i]=str;
        }

        NQueens(0,ans,board,n);
        return ans;

        
}

//Optimal appraoch
void NQueens(int col,vector<vector<string>> &ans,vector<string> &board,int n,vector<int> &left,vector<int> &lower,vector<int> &upper){

        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(!left[row] && !lower[row + col] && !upper[n - 1 + col - row]){

                board[row][col] = 'Q';
                left[row] = 1;
                lower[row + col] = 1;
                upper[n - 1 + col - row] = 1;
                NQueens(col+1,ans,board,n,left,lower,upper);
                board[row][col] = '.';
                left[row] = 0;
                lower[row + col] = 0;
                upper[n - 1 + col - row] = 0;
            }
        }
}
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>board(n);
        string str(n,'.');
        for(int i=0;i<n;i++){
            board[i]=str;
        }

        vector<int>left(n,0);
        vector<int>lower(2*n-1,0);
        vector<int>upper(2*n-1,0);

        NQueens(0,ans,board,n,left,lower,upper);
        return ans;

        
    }