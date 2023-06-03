#include<bits/stdc++.h>
using namespace std;

//Application of Floyd Warshall algorithm
//Time complexity--->O(n^3)
//Space complexity--->O(n*n)
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,-1));
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            matrix[u][v]=wt;
            matrix[v][u]=wt;
        }
        for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][via]!=-1 && matrix[via][j]!=-1){
	                    int cost=matrix[i][via]+matrix[via][j];
	                    if(matrix[i][j]==-1 || cost<matrix[i][j]) matrix[i][j]=cost;
	                }
	            }
	        }
	    }

        int city=-1,minCnt=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j]<=distanceThreshold) cnt++; 
            }
            if(cnt<=minCnt){
                minCnt=cnt;
                city=i;
            }
        }

        return city;

}

//Done using Dijkstra Algorithm
//Time compplexity---->O(V * (2V+E)) 
vector<int>dijkstra(int n,vector<vector<pair<int,int>>> &adj,int src){

        vector<int>dist(n,1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,src});
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

        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int city=-1,minCnt=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int>djk=dijkstra(n,adj,i);
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && djk[j]<=distanceThreshold) cnt++; 
            }
             if(cnt<=minCnt){
                minCnt=cnt;
                city=i;
            }
        }

        return city;

}