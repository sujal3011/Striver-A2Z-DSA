#include<bits/stdc++.h>
using namespace std;

//Time complexity-->O(logn)
//Space complexity-->O(1)
long long int floorSqrt(long long int x) 
    {
        long long int low=1,high=x;
        while(low<=high){
            long long mid=(low + high)/2;
            if((mid*mid)<=x){
                low = mid + 1; 
            }
            else{
                high = mid-1;
            }
        }
        
        return high;
}