#include<bits/stdc++.h>
using namespace std;

//First approach
//Time complexity--->O(n^2)
//Space complexity--->O(1)
void swap(int &a,int &b){
        a=a+b;
        b=a-b;
        a=a-b;
    }

    void swapper(vector<vector<int>>& a,int i1,int j1,int i2,int j2,int i3,int j3,int i4,int j4){
        swap(a[i1][j1],a[i4][j4]);
        swap(a[i4][j4],a[i3][j3]);
        swap(a[i3][j3],a[i2][j2]);
    }

    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0,j=n-2;
        while(i<=j){
            for(int k=i;k<=j;k++){
                swapper(matrix,i,k,k,n-i-1,n-i-1,n-k-1,n-k-1,i);
            }
            i++;
            j--;
        }
}


//Second approach

//Time complexity--->O(n^2)
//Space complexity--->O(1)

void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        //Transposing the matrix

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //Reversing the rows of the matrix

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }


int main(){

    return 0;
}