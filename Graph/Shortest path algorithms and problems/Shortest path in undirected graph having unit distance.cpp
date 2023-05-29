#include<bits/stdc++.h>
using namespace std;


//This solution works for unweighted graph (or when all the edge weights are same)
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>>adj(N);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(N,-1);
        queue<pair<int,int>>q;
        vector<int>visited(N,0);
        q.push({src,0});
        visited[src]=1;
        while(!q.empty()){
            int node=q.front().first;
            int distance=q.front().second;
            q.pop();
            ans[node]=distance;
            for(auto child:adj[node]){
                if(!visited[child]){
                    q.push({child,distance+1});
                    visited[child]=1;
                }
            }
            
        }
        return ans;
}


//This solution will work for weighted undirected graph 
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>>adj(N);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>dist(N);
        for(int i=0;i<N;i++){
            dist[i]=1e9;
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        while(!q.empty()){
            int node=q.front().first;
            int distance=q.front().second;
            q.pop();
            for(auto child:adj[node]){
                if(dist[child] > distance + 1 ){  //If the graph is weighted then instead of '1' we will be adding 'weight of that edge' to the distance. 
                    dist[child]=distance+1;
                    q.push({child,distance + 1});
                }
            }
            
        }
        for(int i=0;i<N;i++){
           if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
        
    }