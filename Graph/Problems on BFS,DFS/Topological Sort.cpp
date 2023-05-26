#include<bits/stdc++.h>
using namespace std;

//Using DFS
//Time complexity--->same as DFS
//Space complexity--->O(2*N),for a stack and the visited array
void dfs( vector<int> adj[],vector<int> &visited,stack<int> &st,int node){
	    visited[node]=1;
	    for(auto child : adj[node]){
	        if(!visited[child]) dfs(adj,visited,st,child);
	    }
	    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    vector<int>visited(V,0);
	    for(int i=0;i<V;i++){
	        if(!visited[i]) dfs(adj,visited,st,i);
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
}


//Using BFS/Kahn's algorithm
//Time complexity--->O(V+E),same as BFS
//Space complexity--->O(2*N),extra space for queue and indegrees array
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	         if(indegree[i]==0) q.push(i);
	    }
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto child:adj[node]){
	            indegree[child]--;
	            if(indegree[child]==0) q.push(child);
	        }
	        
	    }
	    return topo;
	     
}