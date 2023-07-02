#include<bits/stdc++.h>
using namespace std;

//Brute force
//Time complexity-->O(n^2)
//Space complexity-->O(1)

//Optimal appraoch
//Time complexity-->O(n)
//Space complexity-->O(1)

int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    
    int n=gas.size();
        int gasSum=0,costSum=0;
        for(int i=0;i<n;i++){
            gasSum+=gas[i];
            costSum+=cost[i];
        }

        if(gasSum<costSum) return -1;
        int total=0,idx=-1;
        for(int i=0;i<n;i++){
            if(total==0) idx=i;
            total+=(gas[i]-cost[i]);
            if(total<0) total=0;
        }

        return idx;
        
    }

