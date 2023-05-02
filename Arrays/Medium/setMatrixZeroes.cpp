#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(n*m*(n+m))--->O(n^3)
//Space complexity--->O(n*m)
 void setZeroes(vector<vector<int>>& matrix) {

        int m=matrix.size(),n=matrix[0].size();
        vector<pair<int,int>>zeroes;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }

        for(auto it:zeroes){
            for(int k=0;k<n;k++){
                matrix[it.first][k]=0;
            }

            for(int k=0;k<m;k++){
                matrix[k][it.second]=0;
            }
        }
 }

//Time complexity-->O(n*m)-->O(n^2)
//Space complexity--->O(n+m)
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>rows(m);
        vector<int>columns(n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    columns[j]=1;
                }
            }
        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(rows[i]==1 || columns[j]==1) matrix[i][j]=0;
            }

    }


//Most optimized approach
//Time complexity-->O(n*m)-->O(n^2)
//Space complexity--->O(1)
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),temp=1;
        //row[n]-->matrix[0]
        //coloumn[n]-->matrix[..][0]

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){

                    matrix[i][0]=0;
                    if(j==0) temp=0;
                    else matrix[0][j]=0;

                }
            }
        }

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }

        for(int i=0;i<n;i++){
            if(matrix[0][0]==0) matrix[0][i]=0;
        }

        for(int i=0;i<m;i++){
            if(temp==0) matrix[i][0]=0;
        }


    }

int main(){

    return 0;
}