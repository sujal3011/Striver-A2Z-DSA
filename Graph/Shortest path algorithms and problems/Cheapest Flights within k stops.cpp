#include<bits/stdc++.h>
using namespace std;


//modified dijkstra algorithm
//Using priority queue
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int>dist(n,1e9);
        dist[src]=0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second.first;
            int distance=it.second.second;
            int stops=it.first;
            for(auto it:adj[node]){
                int child=it.first;
                int weight=it.second;
                if(stops+1<=k+1 && distance+weight<dist[child]){
                    dist[child]=distance+weight;
                    pq.push({stops+1,{child,distance+weight}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
        
}

//modified dijkstra algorithm
//Using queue
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        dist[src]=0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int node=it.second.first;
            int distance=it.second.second;
            int stops=it.first;
            for(auto it:adj[node]){
                int child=it.first;
                int weight=it.second;
                if(stops+1<=k+1 && distance+weight<dist[child]){
                    dist[child]=distance+weight;
                    pq.push({stops+1,{child,distance+weight}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
        
}