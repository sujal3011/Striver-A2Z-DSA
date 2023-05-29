#include<bits/stdc++.h>
using namespace std;


//Approach 1---> Detecting a cycle in a directed graph

//Time complexity--->same as dfs
//Space complexity---->O(2*N) extra space for visited and path visited arrays  
bool dfs(vector<vector<int>> &adj,int node,vector<int> &visited,vector<int> &pathVisited,vector<int> &check){
        visited[node]=1;
        pathVisited[node]=1;
        for(auto child:adj[node]){
            if(!visited[child]){
                if(dfs(adj,child,visited,pathVisited,check)){  //this means that the child is part of a cycle so this node is directing to a cycle so it can't be a safe node
                    check[node]=0;
                    return true;
                }
            }
            if(pathVisited[child]){  //this means that the node is itself a part of a cycle so it can't be a safe node
                 check[node]=0;
                 return true;
            }
        }
        pathVisited[node]=0;
        check[node]=1;  //node is a safe node
        return false;
        
    }
vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>visited(n,0);
        vector<int>pathVisited(n,0);
        vector<int>check(n,0);
        vector<int>safeNodes;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited,pathVisited,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]) safeNodes.push_back(i);
        }

        return safeNodes;
}


//Space optimized solution (using only a single visited array)
//Time complexity--->same as dfs
//Space complexity---->O(N) extra space for visited array 

 bool dfs(vector<vector<int>> &adj,int node,vector<int> &visited,vector<int> &check){
        visited[node]=2;
        for(auto child:adj[node]){
            if(!visited[child]){
                if(dfs(adj,child,visited,check)){
                    check[node]=0;
                    return true;
                }
            }
            if(visited[child]==2){
                 check[node]=0;
                 return true;
            }
        }
        visited[node]=1;
        check[node]=1;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>visited(n,0);
        vector<int>check(n,0);
        vector<int>safeNodes;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]) safeNodes.push_back(i);
        }

        return safeNodes;
}

//Using BFS/Kahn's Algorithm/TopoSort
//Time complexity--->O(V+E) + O(nlogn),extra time for sorting the array of safe nodes
//Space complexity--->O(2*N),extra space for queue and indegrees array and also extra space for storing the reversed graph
 vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>revAdj(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]) revAdj[it].push_back(i);  //Reversing the edges of the given graph
        }

        //Performing toposort on the reversed graph
        vector<int>indegrees(n,0);
        for(int i=0;i<n;i++){
            for(auto it:revAdj[i]){
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
            for(auto child:revAdj[node]){
                indegrees[child]--;
                if(indegrees[child]==0) q.push(child);
            }
        }
        
        // sorting the array o safe nodes
       sort(topo.begin(),topo.end());
       return topo;
    }

