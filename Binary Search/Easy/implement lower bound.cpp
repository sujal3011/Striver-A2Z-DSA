#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
int findFloor(vector<long long> v, long long n, long long x){
        
        long long start=0,end=n-1,ans=-1;
        while(start<=end){
            long long mid=(start+end)/2;
            
            if((v[mid]==x) || (v[mid]<x && (mid+1)>=n) || (v[mid]<x && v[mid+1]>x) ){
                ans=mid;
                break;
            }
            else if(v[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return ans;
        
}


int main(){

    return 0;
}