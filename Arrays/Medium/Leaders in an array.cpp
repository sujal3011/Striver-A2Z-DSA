#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(n)
//Space complexity--->O(1)
vector<int> leaders(int a[], int n){
        vector<int>ans;
        ans.push_back(a[n-1]);
        int maxi=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>=maxi){
                ans.push_back(a[i]);
                maxi=a[i];
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }


int main(){

    return 0;
}