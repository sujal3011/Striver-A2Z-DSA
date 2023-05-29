#include<bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
        int M=100000;
        queue<pair<int,int>>q;
        vector<int>dist(M,1e9);
        q.push({0,start});
        dist[start]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.second;
            int distance=it.first;
            for(auto it:arr){
                int child=(node*it)%M;
                if(distance+1<dist[child]){
                    dist[child]=distance+1;
                    if(child==end) return dist[child];
                    q.push({distance+1,child});
                }
            }
        }
        
        return -1;
    }