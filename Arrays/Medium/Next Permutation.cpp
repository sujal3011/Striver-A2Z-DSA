#include<bits/stdc++.h>
using namespace std;

//Function to find all possible permutations using backtracking
//Time complexity--->O(N*N!)
//Space complexity--->O(1)
void recPermutation(int idx,vector<int>&nums,vector<vector<int>>&ans){

    if(idx==nums.size()){
        vector<int>temp=nums;
        ans.push_back(temp);
        return;

    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        recPermutation(idx+1,nums,ans);
        swap(nums[i],nums[idx]);
    }
}

//Brute force solution(finding all permutations)
//Time complexity--->O(N*N!)
//Space complexity--->O(1)

void nextPermutation(vector<int>& nums) {

    vector<vector<int>>ans;
    vector<int>final_ans;
    recPermutation(0,nums,ans);

    for(int i=0;i<ans.size();i++){
        if(ans[i]==nums){
            if((i+1)==ans.size()){
                final_ans=ans[0];
                return;
            }
        }
        else{
            final_ans=ans[i+1];
            return;
        }
    }  

    for(auto it:final_ans){
        cout<<it<<" ";
    }   
}

//Optimized solution
//Time complexity---->O(n)
//Space complexity--->O(1)
 void nextPermutation(vector<int>& arr) {
        int n=arr.size();

        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                idx=i;
                break;
            }

        if(idx==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int i=n-1;i>idx;i--){
            if(arr[i]>arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        reverse(arr.begin()+idx+1,arr.end());
    }
 }
int main(){

    return 0;
}