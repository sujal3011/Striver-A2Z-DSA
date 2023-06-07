#include<bits/stdc++.h>
using namespace std;

//Brute approach
//Three pointers
vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        for(int first=0;first<n-2;first++){
            for(int second=first+1;second<n-1;second++){
                for(int third=second+1;third<n;third++){
                    if((nums[first]+nums[second]+nums[third])==0){
                        vector<int>res={nums[first],nums[second],nums[third]};
                        sort(res.begin(),res.end());
                        st.insert(res);
                    }
                }
            }
        }
         vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }

//Hashing
//Better
vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;

        for(int i=0;i<n;i++){
            set<int>hashset;
            for(int j=i+1;j<n;j++){
                auto it=hashset.find(-nums[i]-nums[j]);
                if(it!=hashset.end()){
                    vector<int>temp = {nums[i],nums[j],*it};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }


//Two pointer approach
//Optimal appraoch

 vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(k>j){
                int sum=nums[i]+nums[j]+nums[k];

                if(sum==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    
                    while(j<k && nums[k]==nums[k+1]) k--;
                    

                }
                else if(sum<0){
                    j++;
                }
                else k--;

            }

        }

        return ans;
}