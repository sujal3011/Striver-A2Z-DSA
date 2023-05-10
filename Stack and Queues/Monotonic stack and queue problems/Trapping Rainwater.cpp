#include<bits/stdc++.h>
using namespace std;


//Brute force
//Time complexity-->O(n^2)
//Space complexity-->O(1)

//Better
//Time complexity-->O(n)+O(n)+O(n)
//Space complexity-->O(2*n)
int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix_max(n);
        vector<int>suffix_max(n);

        //precomputing prefix_max
        int maxi=height[0];
        for(int i=0;i<n;i++){
            if(maxi>height[i]){
                prefix_max[i]=maxi;
            }
            else{
                prefix_max[i]=height[i];
                maxi=height[i];
            }
        }
        //precomputing suffix_max
        maxi=height[n-1];
        for(int i=n-1;i>=0;i--){
            if(maxi>height[i]){
                suffix_max[i]=maxi;
            }
            else{
                suffix_max[i]=height[i];
                maxi=height[i];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(prefix_max[i],suffix_max[i])-height[i]);
        }

        return ans;
}


//Optimal
//Two pointer appraoch
//Time complexity-->O(n)
//Space complexity-->O(1)
int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,res=0;
        int maxleft=0,maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];

                left++;
            }
            else{
                if(height[right]>=maxright) maxright=height[right];
                else res+=maxright-height[right];

                right--;
            }
        }
        return res;
    }

int main(){

    return 0;
}