#include<bits/stdc++.h>
using namespace std;

//Time complexity-->O(n1+n2)
//Space complexity-->O(n2)
//Considering the array to be non circular
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        vector<int>precomp(100001);
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
                
            if(st.empty()) precomp[nums2[i]]=-1;
            else precomp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++) ans.push_back(precomp[nums1[i]]);
        return ans;

}

int main(){

    return 0;
}