#include<bits/stdc++.h>
using namespace std;


//Straight forward application of Dijkstra algorithm
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int distance=it.first;
            for(auto it:adj[node]){
                int child=it.first;
                int weight=it.second;
                if(distance+weight<dist[child]){
                    dist[child]=distance+weight;
                    pq.push({distance+weight,child});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            else if(dist[i]>ans) ans=dist[i];
        }

        return ans;
}