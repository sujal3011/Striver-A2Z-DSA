#include<bits/stdc++.h>
using namespace std;

//Implementation of finding shortest path in an undirected graph having unit weight
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return -1;

        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{0,0},0});
        visited[0][0]=1;
        int X[]={0,1,1,1,0,-1,-1,-1};
        int Y[]={1,1,0,-1,-1,-1,0,1};
        while(!q.empty()){
            int nodeX=q.front().first.first;
            int nodeY=q.front().first.second;
            int distance=q.front().second;
            q.pop();
            dist[nodeX][nodeY]=distance;
            for(int i=0;i<8;i++){
                int adjX=nodeX+X[i];
                int adjY=nodeY+Y[i];
                if(adjX>=0 && adjX<n && adjY>=0 && adjY<n && grid[adjX][adjY]==0 && !visited[adjX][adjY]){
                    q.push({{adjX,adjY},distance+1});
                    visited[adjX][adjY]=1;
                }
            }

        }

        if(dist[n-1][n-1]==-1) return -1;
        return dist[n-1][n-1]+1;

}