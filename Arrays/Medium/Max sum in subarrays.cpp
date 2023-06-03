#include<bits/stdc++.h>
using namespace std;

//GFG
//Optimal solution
//Observation based
//Time complexity--->O(n)
//Space complexoty--->O(1)

long long pairWithMaxSum(long long arr[], long long N)
{
       long long maxi=arr[0]+arr[1];
       for(int i=1;i<N-1;i++){
           long long sum=arr[i]+arr[i+1];
           if(sum>maxi){
               maxi=sum;
           }
       }
       return maxi;
}

int main(){

    return 0;
}