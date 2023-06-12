 #include<bits/stdc++.h>
using namespace std;
 
//Brute force approach
//Time complexity-->O(n^2)
//Space complexity-->O(1)

//Optimal approach
//Observation
//Time complexity-->O(n)
//Space complexity-->O(1)

 int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int prefix_product=1,suffix_product=1;
        for(int i=0;i<n;i++){
            if(prefix_product==0) prefix_product=1;
            if(suffix_product==0) suffix_product=1;
            prefix_product*=nums[i];
            suffix_product*=nums[n-i-1];
            ans=max(ans,max(prefix_product,suffix_product));

        }
        return ans;
}