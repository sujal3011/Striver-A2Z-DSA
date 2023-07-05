#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


//Optimized approach
//Time complexity--->O(n! * n)
//Space complexity--->O(n) +  O(n)  ,only for recursive stack space,not using temp array or taken array
//Using the same logic for generating all permutations, only using an extra unordered set
void generatePermutations(int idx,vector<int>&nums,vector<vector<int>> &ans){

        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){

            if(st.find(nums[i])!=st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            generatePermutations(idx+1,nums,ans);
            swap(nums[i],nums[idx]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>>ans;
        generatePermutations(0,nums,ans);
        return ans;
        
    }