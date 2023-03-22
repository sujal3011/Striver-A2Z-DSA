#include<bits/stdc++.h>
using namespace std;

//Hashing
//Time complexity--->O(n)
//Space complexity-->O(n)
vector<int> twoSum(vector<int>& arr, int k) {
        unordered_map<int,int>mm;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mm[arr[i]]=i;
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(mm[k-arr[i]] && mm[k-arr[i]]!=i ){
                ans.push_back(i);
                ans.push_back(mm[k-arr[i]]);
                break;
            }
        }

        return ans;
}


//Two pointer approach
//Time complexity--->O(nlogn)
//Space complexity--->O(n)

vector<int> twoSum(vector<int>& arr, int k) {
        int n=arr.size();

        vector<int>ans,temp;
        temp=arr;
        sort(temp.begin(),temp.end());

        int left=0,right=n-1;
        int n1,n2;
        while(left<right){
            if(temp[left]+temp[right]==k){
               n1=temp[left];
               n2=temp[right];
               break;
            }
            else if(temp[left]+temp[right]>k){
                right--;
            }
            else left++;
        }

        for(int i=0;i<n;i++){
            if(arr[i]==n1){
                ans.push_back(i);
            }
            else if(arr[i]==n2){
                ans.push_back(i);
            }
        }

        return ans;
    }




int main(){

    return 0;
}