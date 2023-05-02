#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
int search(vector<int>& arr, int target) {

        int n=arr.size();
        int low=0,high=n-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                ans=mid;
                break;
            }
            else if( (mid-1)>=0 && mid>low && arr[low]<=arr[mid-1] ){
                if(target>=arr[low] && target<=arr[mid-1]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if((mid+1)<n && target>=arr[mid+1] && target<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

        }
        return ans;
}

int main(){

   vector<int>arr={1,1,1,1,1,1,1,1,2,1};
   int target=2;

   cout<<search(arr,target)<<"\n";

    return 0;
}

