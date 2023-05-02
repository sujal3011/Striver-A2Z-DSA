#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
int searchInsert(vector<int>& arr, int target) {

        int start=0,end=arr.size()-1,idx=-1;
        while(start<=end){
            int mid=(start+end)/2;

            if(arr[mid]==target){
                idx=mid;
                break;
            }
            else if(arr[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        if(idx==-1) idx=start;
        return idx;
        
    }

int main(){

    return 0;
}