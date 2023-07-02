#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(nlogn)
//Space complexoty--->O(1)
//Using sorting
int firstMissingPositive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]<=0) i++;
            else break;
        }
        if(i==n || nums[i]>1) return 1;
        i++;
        while(i<n){
            if(nums[i]==(nums[i-1]+1) || nums[i]==nums[i-1]) i++;
            else break;
        }
        return nums[i-1]+1;
        
    }

//Time complexity--->O(n)
//Space complexoty--->O(n)
//Using visited array
//Maximum value of first missing positive number can be (n+1),where n is the size of the array
int firstMissingPositive(vector<int>& nums) {

        int n=nums.size();
        vector<int>visited(n+2,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i]<n+2) visited[nums[i]]=1; 
        }
        int ans=-1;
        for(int i=1;i<=n+1;i++){
            if(!visited[i]){
                ans=i;
                break;
            }
        }
        
        return ans;
        
}


//Time complexity--->O(3*n)-->O(n)
//Space complexoty--->O(1)
//Most optimized approach,using the existing array only to keep a track of the elements present
//https://youtu.be/8g78yfzMlao
int firstMissingPositive(vector<int>& nums) {

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]=0;
        }
        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1;
            if(idx>=0 && idx<n){
                if(nums[idx]>0) nums[idx] = -(nums[idx]);
                else if(nums[idx]==0) nums[idx] = -(n+1);      
            }
        }

        int ans=n+1;
        for(int i=1;i<=n;i++){
            if(nums[i-1]>=0){
                ans=i;
                break;
            }
        }

        return ans;     
}