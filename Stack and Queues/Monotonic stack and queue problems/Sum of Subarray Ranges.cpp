#include<bits/stdc++.h>
using namespace std;

//Brute force solution
//Time complexity---O(n^2)
//Space complexity-->O(1)
long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX,maxi=INT_MIN;
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                ans+=(maxi-mini);
            }
        }
        return ans;
}

//Optimal solution
//This problem is a combination of 2 problems
//1.Sum of Subarray minimums
//1.Sum of Subarray maximums
//Using monotonic stack
//Time complexity---O(n)
//Space complexity-->O(n)

vector<int> getNSL(vector<int>& nums , int n){
        vector<int> v(n);
        stack<int> s;
        for(int i = 0 ;i<n;i++){
            if(s.empty()){
            v[i]=-1;
            }else{
                 while(s.size()!=0 && nums[s.top()]>nums[i]){
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=-1;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }
    //finding NSR
     vector<int> getNSR(vector<int>& nums , int n){
        vector<int> v(n);
                stack<int> s;

        for(int i = n-1 ;i>=0;i--){
            if(s.empty()){
            v[i]=n;
            }else{
                 while(s.size()!=0 && nums[s.top()]>=nums[i]){
                     //we handle duplicates by = sign in one case
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=n;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }
    // finding NGR
    vector<int> getNGR(vector<int>& nums , int n){
        vector<int> v(n);
                stack<int> s;

        for(int i = n-1 ;i>=0;i--){
            if(s.empty()){
            v[i]=n;
            }else{
                 while(s.size()!=0 && nums[s.top()]<=nums[i]){
                     //we handle duplicates by = sign in one case
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=n;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }
    //finding NGL
    vector<int> getNGL(vector<int>& nums , int n){
        vector<int> v(n);
                stack<int> s;

        for(int i = 0 ;i<n;i++){
            if(s.empty()){
            v[i]=-1;
            }else{
                 while(s.size()!=0 && nums[s.top()]<nums[i]){
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=-1;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }

   // approach for this is same as sum of minimums in a subarray
   // first we find  the sum of maximums in a subarray 
   //second we find the sum of minimums in a subarray 
   //later we subtarct them and we get the sum of ranges 
   // sum of maximums of two arrays be a + b
   // sum of minimums of two arrays be c + d
   //we suntract (a+b)-(c+d);
   // we can write as (a-c)+(b-d)
   
    long long subarrayRanges(int n, vector<int> &nums) {
        vector<int> NGL = getNGL(nums,n);
        vector<int> NGR = getNGR(nums,n);
        vector<int> NSL = getNSL(nums,n);
        vector<int> NSR = getNSR(nums,n);
        for(auto x:NGL) cout<<x<<" ";
        cout<<endl;
        for(auto x:NGR) cout<<x<<" ";
        cout<<endl;
        for(auto x:NSL) cout<<x<<" ";
        cout<<endl;
        for(auto x:NSR) cout<<x<<" ";
        cout<<endl;
        long long sum = 0;
        for(int i =0;i<n;i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i]-i;
            long long lg = i - NGL[i];
            long long rg = NGR[i]-i;
            long long totalsum = ((lg*rg)-(ls*rs))*nums[i];
            sum = sum+totalsum;
        }
        return sum ;
    
}

int main(){

    return 0;
}