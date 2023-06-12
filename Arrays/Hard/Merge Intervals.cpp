#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(nlogn) + O(n)
//Space complexity--->O(1)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1],i=1;
        vector<vector<int>>ans;
        while(i<n){
            if(end<intervals[i][0]){
                vector<int>interval={start,end};
                ans.push_back(interval);
                start=intervals[i][0];
                end=intervals[i][1];
            }else if(intervals[i][1]>end) end=intervals[i][1];
            i++;
        }
        vector<int>interval={start,end};
        ans.push_back(interval);
        return ans;

    }