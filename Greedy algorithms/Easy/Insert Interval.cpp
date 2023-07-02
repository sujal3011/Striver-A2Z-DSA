#include<bits/stdc++.h>
using namespace std;

//Approach 1
//Using the concept of merging overlapping intervals
//Time complexcity--->O(nlogn) + O(n)
//Space comkplexity--->O(1)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>>ans;

       intervals.push_back(newInterval);
       int n=intervals.size();
       sort(intervals.begin(),intervals.end());
       int start=intervals[0][0],end=intervals[0][1],i=1;
       while(i<n){
           if(end<intervals[i][0]){
               vector<int>interval={start,end};
               ans.push_back(interval);
               start=intervals[i][0];
               end=intervals[i][1];
           }
           else if(intervals[i][1]>end) end=intervals[i][1];
           i++;
       }
       vector<int>interval={start,end};
       ans.push_back(interval);
       return ans;
}

//Approach 2
//Time complexcity--->O(n)
//Space comkplexity--->O(1)

 vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) { 
    vector<Interval> res;
    for (Interval test : intervals) {
        if (newInterval.start > test.end) res.push_back(test);
        else if(test.start > newInterval.end) {
            res.push_back(newInterval);
            newInterval = test;
        } else if (newInterval.start <= test.end || newInterval.end >= test.start) {
            newInterval = Interval(min(test.start, newInterval.start), max(test.end, newInterval.end));
        }
    } 
    res.push_back(newInterval);
    return res;
}