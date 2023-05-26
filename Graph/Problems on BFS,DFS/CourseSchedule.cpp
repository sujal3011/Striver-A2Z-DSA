#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj,vector<int> &visited,int node){
        visited[node]=2;
        for(auto child:adj[node]){
            if(!visited[child]){
                if(dfs(adj,visited,child)) return true;
            }
            else if(visited[child]==2) return true;
        }
        visited[node]=1;
        return false;
    }

bool detectCycle(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i] && dfs(adj,visited,i)) return true;
        }
        return false;
}

//Implementation of detecting cycle in directed graph
//TC---->same as DFS
//SC---->O(N) extra space for visited array
bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
         if(detectCycle(numCourses,prerequisites)) return false;
         return true;
}


//Using BFS/Kahn's algorithm
//Time complexity--->O(V+E),same as BFS
//Space complexity--->O(2*N),extra space for queue and indegrees array
bool detectCycle(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }


        vector<int>indegrees(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegrees[it]++;
            }
        }
        
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++){
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
        
        if(topo.size()==n) return false;
        return true;
    }

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
         if(detectCycle(numCourses,prerequisites)) return false;
         return true;
}