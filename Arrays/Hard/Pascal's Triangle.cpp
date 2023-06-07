#include<bits/stdc++.h>
using namespace std;

//Brute force appraoch
//Time complexity--->O(n cube)
//Space complexity--->O(1)
int nCr(int n,int r){
        long long res=1;
        for(int i=0;i<r;i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return res;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>temp;
            for(int j=1;j<=i;j++){
                temp.push_back(nCr(i-1,j-1));
            }
            ans.push_back(temp);
        }
        return ans;
}


//Optimal appraoch
//Time complexity--->O(n square)
//Space complexity--->O(1)

vector<int>generateRow(int row){
            vector<int>temp;
            int res = 1;
            temp.push_back(res);
            for(int col = 1;col<row;col++){
                res = res*(row-col);
                res = res/col;
                temp.push_back(res);
            }
        return temp;
}

vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int row=1;row<=numRows;row++){
            
            ans.push_back(generateRow(row));
            
        }
        return ans;
}

int main(){

    return 0;
}