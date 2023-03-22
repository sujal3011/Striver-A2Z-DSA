#include<bits/stdc++.h>
using namespace std;

//Storing cnt of 0,1,2
//Time complexity--->O(2*n)....two passes required
//Space complexity--->O(n)
void sortColors(vector<int>& arr) {
        int n=arr.size();
        int zero_cnt=0,one_cnt=0,two_cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) zero_cnt++;
            else if(arr[i]==1) one_cnt++;
            else two_cnt++;
        }
        int i=0;
        for(int j=0;j<zero_cnt;j++){
            arr[i]=0;
            i++;
        }

        for(int j=0;j<one_cnt;j++){
            arr[i]=1;
            i++;
        }

        for(int j=0;j<two_cnt;j++){
            arr[i]=2;
            i++;
        }
}

//3 pointer approach
//Dutch national flag algorithm
//Time complexoty--->O(n)....only single pass required
//Space complexity--->O(1)

void sortColors(vector<int>& arr) {
        int n=arr.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }

    }




int main(){

    return 0;
}