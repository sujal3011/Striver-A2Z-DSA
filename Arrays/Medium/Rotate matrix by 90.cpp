#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Time complexity--->O(n*n)
//Space complexity--->O(n*n)
void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-i-1]=matrix[i][j];
            }
        } 
        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=ans[i][j];
            }
         } 



}


//Second approach

//Time complexity--->O(n)
//Space complexity--->O(1)

void reverse(vector<int>&arr){
        int n=arr.size();
        for(int i=0;i<n/2;i++){
            swap(arr[i],arr[n-i-1]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {

        int n=matrix.size();
       
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        } 

        for(int i=0;i<n;i++){
            reverse(matrix[i]);
        }

}


int main(){

    return 0;
}