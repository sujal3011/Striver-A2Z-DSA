#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
//Finding first and last occurences of target and calculating the number of occurences
int count(int nums[], int n, int target) {
	
        int start=0,end=n-1,fi=-1,ei=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid]==target){
               
                fi=mid;
                end=mid-1;
                
            }
        }

        start=0,end=n-1;

        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid]==target){
               
               ei=mid;
               start=mid+1;
                
            }
        }
        
        if(fi==-1){
            return 0;
        }
        
        return (ei-fi+1);
	}

int main(){

    return 0;
}