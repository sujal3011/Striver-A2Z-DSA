#include<bits/stdc++.h>
using namespace std;


//Brute approach
//Extending the logic of sum combination 1
void findCombinations(int i,vector<int>& candidates,int n,int target,set<vector<int>> &ans,vector<int> &comb){

        if(i==n){
            if(target==0) ans.insert(comb);
            return;
        }

        if(candidates[i]<=target){

            comb.push_back(candidates[i]);
            findCombinations(i+1,candidates,n,target-candidates[i],ans,comb);
            comb.pop_back();
        }

        findCombinations(i+1,candidates,n,target,ans,comb);
    }

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    
    int n=candidates.size();
    sort(candidates.begin(),candidates.end());
    set<vector<int>>ans;
    vector<int>comb;
    findCombinations(0,candidates,n,target,ans,comb);
    vector<vector<int>> res(ans.begin(), ans.end());
    return res;

}


//Optimized approach
//Without using set
void findCombinations(int idx,vector<int>& candidates,int n,int target,vector<vector<int>> &ans,vector<int> &comb){

        if(target==0){
            ans.push_back(comb);
            return;
        }

        for(int i=idx;i<n;i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

            comb.push_back(candidates[i]);
            findCombinations(i+1,candidates,n,target - candidates[i],ans,comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>comb;
        sort(candidates.begin(),candidates.end());
        findCombinations(0,candidates,n,target,ans,comb);
        return ans;

        
    }


int main(){


    return 0;
}