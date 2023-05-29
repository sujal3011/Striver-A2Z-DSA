#include<bits/stdc++.h>
using namespace std;


//Time complexity--->O(V x E)
//Use this algorithm if the graph contains negative edges or negative cycles
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=1;i<=V;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]+wt<dist[v]){
                    if(i==V) return {-1};  //if relaxation of edge takes place during the Nth iteration then there is negative cycle present
                    dist[v]=dist[u]+wt;
                }
            }
        }
        return dist;
    }