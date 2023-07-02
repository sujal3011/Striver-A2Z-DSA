#include<bits/stdc++.h>
using namespace std;

void findCombinations(int i,vector<int>& candidates,int n,int target,vector<vector<int>> &ans,vector<int> &comb){

        if(i==n){
            if(target==0) ans.push_back(comb);
            return;
        }

        if(candidates[i]<=target){

            comb.push_back(candidates[i]);
            findCombinations(i,candidates,n,target-candidates[i],ans,comb);
            comb.pop_back();
        }

        findCombinations(i+1,candidates,n,target,ans,comb);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>comb;
        findCombinations(0,candidates,n,target,ans,comb);
        return ans;

}

int main(){


    return 0;
}