#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Time complexity--->O(n*m*(n+m))+O(n*m)--->O(n^3)
//Space complexity--->O(1)
  void markRow(int i,vector<vector<int>>& matrix,int n){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=1e9+5;
            }
        }
    }

    void markCol(int i,vector<vector<int>>& matrix,int m){
        for(int j=0;j<m;j++){
            if(matrix[j][i]!=0){
                matrix[j][i]=1e9+5;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    markRow(i,matrix,n);
                    markCol(j,matrix,m);
                }
            }
        }

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1e9+5) matrix[i][j]=0;
            }
         }


    }

//Better approach
//Time complexity-->O(2*n*m)-->O(n^2)
//Space complexity--->O(n+m)
 void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
         }

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
         }

}

//Most optimized approach
//Time complexity-->O(n*m)-->O(n^2)
//Space complexity--->O(1)
 void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //vector<int>row(m,0);---->matrix[..][0]
        //vector<int>col(n,0);---->matrix[0][..]

        int col=1;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){

                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col=0;
                    }
                }
            }
         }

         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
         }

         for(int i=1;i<n;i++){
             if(matrix[0][0]==0) matrix[0][i]=0;
         }
         for(int i=0;i<m;i++){
             if(col==0) matrix[i][0]=0;
         }


}
int main(){

    return 0;
}