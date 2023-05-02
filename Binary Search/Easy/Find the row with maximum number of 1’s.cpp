#include<bits/stdc++.h>
using namespace std;

//Optimized solution(Binary Search)
//Time complexity--->O(logn)
//Space complexity--->O(1)
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans=-1,max_cnt=0;
	    for(int i=0;i<n;i++){
	        vector<int>temp=arr[i];
	        int start=0,end=m-1,idx=-1;
	        
	        while(start<=end){
	            int mid=(start+end)/2;
	            
	            if( (temp[mid]==1 && mid==0) || (temp[mid]==1 && temp[mid-1]==0) ){
	                idx=mid;
	                break;
	            }
	            
	            
	            if(temp[mid]==0){
	                start=mid+1;
	            }
	            else if(temp[mid]==1){
	                end=mid-1;
	            }
	        }
	        
	        if(idx!=-1){
	            int cnt=m-idx;
	            if(cnt>max_cnt){
	                max_cnt=cnt;
	                ans=i;
	            }
	        }
	        
	       
	        }
        
	    
	    return ans;
}


int main(){

    return 0;
}