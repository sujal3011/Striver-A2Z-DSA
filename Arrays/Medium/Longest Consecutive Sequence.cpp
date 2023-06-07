#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

//Sorting approach
//Time complexity-->O(nlogn) + O(n)
//Space complexity-->O(1)

int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int largest=0,cnt=0,lastSmallest=INT_MIN;

        for(int i=0;i<arr.size();i++){
            if(arr[i]==(lastSmallest+1)){
                cnt++;
                largest=max(largest,cnt);
                lastSmallest=arr[i];
            }
            else if(arr[i]!=lastSmallest){
                cnt=1;
                lastSmallest=arr[i];
            }
        }
        largest=max(largest,cnt);
        return largest;
}

//Optimized approach
//Time complexity--->O(N)
//Space complexity--->O(N)
int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>ss;
        for(int i=0;i<n;i++){
            ss.insert(arr[i]);
        }

        int max_cnt=0;

        for(int i=0;i<n;i++){
            if(!ss.count(arr[i]-1)){
                int curr_cnt=1;
                int curr_num=arr[i];

                while(ss.count(curr_num+1)){
                    curr_cnt++;
                    curr_num++;
                }

                max_cnt=max(max_cnt,curr_cnt);
            }
        }

        return max_cnt;
}


int main(){

    return 0;
}