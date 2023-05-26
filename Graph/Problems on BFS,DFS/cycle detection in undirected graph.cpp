#include<bits/stdc++.h>
using namespace std;


//Using BFS
bool bfs(vector<int>adj[],int n,int src,vector<int>&visited){
        queue<pair<int,int>>q;
        q.push({src,-1});
        visited[src]=1;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int parent=it.second;
            q.pop();
            for(auto child:adj[node]){
                if(!visited[child]){
                    q.push({child,node});
                    visited[child]=1;
                }
                else if(child!=parent) return true;
            }
        }
        return false;
}

bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i] && bfs(adj,V,i,visited)) return true;
        }
        return false;
}


//Using DFS
bool dfs(vector<int>adj[],int node,int parent,vector<int>&visited){
        visited[node]=1;
        bool flag=false;
        for(auto child:adj[node]){
            if(!visited[child]){
                 flag |= dfs(adj,child,node,visited);
            }
            else if(child!=parent) return true;
        }
        return flag;
    }

    
bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(adj,i,-1,visited)) return true;
        }
        return false;
}