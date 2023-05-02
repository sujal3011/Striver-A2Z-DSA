#include<bits/stdc++.h>
using namespace std;

//IMPORTANT--->Binary Search on unsorted array
//Time complexity--->O(logn)
//Space complexity--->O(1)
int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int start=0,end=n-1,ans=-1;
	    while(start<=end){
	       int mid=start+(end-start)/2;

           if( (((mid-1)<0 || arr[mid-1]<arr[mid]) && ((mid+1)>=n || arr[mid+1]<arr[mid] )) ){
               ans=mid;
               break;
           }
           else if((mid-1)>=0 && arr[mid-1]>arr[mid] ){
               end=mid-1;
           }

           else if ((mid+1)<n && arr[mid+1]>arr[mid]){
               start=mid+1;
           }
          
	   }

       return ans;
	   
	  
}

int main(){

    return 0;
}