#include<bits/stdc++.h>
using namespace std;


//Brute force solution
//Time complexity--->O(n)
//Space complexity--->O(n)
vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        vector<int>pos;
        vector<int>neg;
        for(auto it:arr){
            if(it>0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }

        vector<int>ans(n);
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans[i]=pos[j];
                j++;
            }
            else{
                ans[i]=neg[k];
                k++;
            }
        }


        return ans;
}

//Optimized approach when order of elements in the output doesn't matter
//Time complexity--->O(n)
//Space complexity--->O(1)
vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            while(arr[i]>0) i++;
            while(arr[j]<0) j--;
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

        i=1,j=n/2+1;
        while(i<n/2){
            swap(arr[i],arr[j]);
            i+=2;
            j+=2;
        }

        return arr;
    }

int main(){

    return 0;
}