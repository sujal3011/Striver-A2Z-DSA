#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],int node,vector<int> &visited,vector<int> &pathVisited){
        visited[node]=1;
        pathVisited[node]=1;
        for(auto child:adj[node]){
            if(!visited[child]){
                if(dfs(adj,child,visited,pathVisited)) return true;
            }
            if(pathVisited[child]) return true;
        }
        pathVisited[node]=0;
        return false;
        
    }

//Using DFS
//Time complexity--->same as dfs
//Space complexity---->O(2*N) extra space for visited and path visited arrays  
bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(adj,i,visited,pathVisited)) return true;
        }
        return false;
}



bool dfs(vector<int> adj[],int node,vector<int> &visited){
        visited[node]=2;
        for(auto child:adj[node]){
            if(!visited[child]){
                if(dfs(adj,child,visited)) return true;
            }
            if(visited[child]==2) return true;
        }
        visited[node]=1;
        return false;
        
}

//Using DFS
//Space optimized solution (using only a single visited array)
//Time complexity--->same as dfs
//Space complexity---->O(N) extra space for visited array 
bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(adj,i,visited)) return true;
        }
        return false;
}

//Uisng BFS(kahn's Algorithm/Top Sort)
//Time complexity--->O(V+E),same as BFS
//Space complexity--->O(2*N),extra space for queue and indegrees array
bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int>indegrees(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegrees[it]++;
            }
        }
        
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<V;i++){
            if(indegrees[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto child:adj[node]){
                indegrees[child]--;
                if(indegrees[child]==0) q.push(child);
            }
        }
        
        if(topo.size()==V) return false;
        return true;
    }