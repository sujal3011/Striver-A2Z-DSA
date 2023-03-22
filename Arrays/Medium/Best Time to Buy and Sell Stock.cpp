#include<bits/stdc++.h>
using namespace std;


//Optimized solution
//Time complexity--->O(n)
//Space complexity--->O(1)
int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int maxProfit=0,mini=INT_MAX;

        for(int i=0;i<n;i++){
            if(arr[i]<mini){
                mini=arr[i];
            }
            else{
                maxProfit=max(maxProfit,arr[i]-mini);
            }
        }

        return maxProfit;
    }


int main(){

    return 0;
}