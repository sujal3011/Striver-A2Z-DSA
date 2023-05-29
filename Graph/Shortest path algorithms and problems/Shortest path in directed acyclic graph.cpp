#include<bits/stdc++.h>
using namespace std;


//Shortest path in directed acyclic graph with edges having different weights 
void topoSort(vector<vector<pair<int,int>>> &adj,vector<int> &visited,stack<int> &st,int node){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it.first]) topoSort(adj,visited,st,it.first);
        }
        st.push(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }

        //Step 1
        //Finding topoSort (using DFS,can use BFS also)
        //Time complexity-->O(N+M),same as DFS
        stack<int>st;
        vector<int>visited(N,0);
        for(int i=0;i<N;i++){
	        if(!visited[i]) topoSort(adj,visited,st,i);
	    }
	    
        //Step 2
        //Taking the nodes from the stack and relaxing the edges 
        //Time complexity--->O(N+M)
	    vector<int>dist(N,1e9);
	    dist[0]=0;

	    while(!st.empty()){
	        int node=st.top();
	        st.pop();  //This is done for N times

	        for(auto it:adj[node]){  //This loop runs for M (number of edges) times in total
	            int child=it.first;
	            int distance=it.second;
	            if((dist[node]+distance)<dist[child]){
	                dist[child]=dist[node]+distance;
	            }
	        }
	    }
	    
	    for(int i=0;i<N;i++){
	        if(dist[i]==1e9) dist[i]=-1;
	    }
	    return dist;
        
}