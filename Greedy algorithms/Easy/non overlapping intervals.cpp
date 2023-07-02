#include<bits/stdc++.h>
using namespace std;

//Time complexcity--->O(nlogn) + O(n)
//Space comkplexity--->O(1)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        if(n==1) return 0;
        int left=0,right=1,cnt=0;
        while(right<n){
            if(intervals[left][1]<=intervals[right][0]){   //no overlapping
                left=right;
                right++;
            }
            else if(intervals[right][1]<=intervals[left][1]){  //overlapping case 1 (right interval is completely inside the left interval)
                cnt++;
                left=right;  //removing the left interval
                right++;
            }
            else if(intervals[right][1]>intervals[left][1]){  //overlapping case 2
                cnt++;
                right++;  //removing the right interval
            }
        }

        return cnt;

    }