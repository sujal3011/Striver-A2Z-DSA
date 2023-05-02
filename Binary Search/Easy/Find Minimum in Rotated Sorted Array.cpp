#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1,ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            ans=min(ans,arr[mid]);
            bool ls=true,rs=true;


            if((mid-1)>=0 && mid>low){
                if(arr[low]>arr[mid-1]) ls=false;
            }
            if((mid+1)<n && arr[mid+1]>arr[high]) rs=false;

            //Base condition(when both left and right halves are sorted,mid is the inflection point)
            if(ls && rs){
                if((mid-1)>=0 && mid>low) ans=min(ans,arr[low]);
                if((mid+1)<n) ans=min(ans,arr[mid+1]);
                break;
            }

            if(ls){
                if((mid-1)>=0 && mid>low) ans=min(ans,arr[low]);
                low=mid+1;
            }

            else if(rs){
                if((mid+1)<n) ans=min(ans,arr[mid+1]);
                high=mid-1;;
            }               
            
        }

        return ans;
}

int main(){



    return 0;
}

