#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


//Brute approach
//Generating all permutations
//Time complexity--->O(n! * n) + O(n!log(n!))
//Space complexity--->O(n) +  O(n)

string IntegerToString(int num){
        string ans="";
        if(num==0) return "0";
        while(num>0){
            ans.push_back(num%10 + '0');
            num/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }

    void generatePermutation(int idx,vector<int> &nums,vector<vector<int>> &ans){

        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){

            swap(nums[i],nums[idx]);
            generatePermutation(idx+1,nums,ans);
            swap(nums[i],nums[idx]);
            
        }
    }
    string getPermutation(int n, int k) {

        vector<int>nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        vector<vector<int>>ans;
        generatePermutation(0,nums,ans);
        sort(ans.begin(),ans.end());

        for(auto it:ans){
            for(auto it2:it) cout<<it2<<" ";
            cout<<endl;
        }

        string res;
        for(auto it:ans[k-1]){
            res+=IntegerToString(it);
        }

        return res;
        
        
    }


//Optimized approach
//Time complexity--->O(n^2)
//Space complexity--->O(n)
string getPermutation(int n, int k) {

        vector<int>nums;
        int fact=1;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans="";
        k--;
        while(true){   //Loop runs for n times
            ans+=(to_string(nums[k/fact]));
            nums.erase(nums.begin() + k/fact);  //Time complexity for erase function is O(n)
            if(nums.size()==0) break;
            k = k % fact;
            fact = fact / nums.size();
        }

        return ans;
} 