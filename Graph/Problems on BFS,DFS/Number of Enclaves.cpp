#include<bits/stdc++.h>
using namespace std;


//Done using DFS 
//Can be done using BFS also
//Time complexity--->O(n*m)
//Space complexity--->O(n*m)
void dfs(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& visited,int X[],int Y[]){
        int n=grid.size(),m=grid[0].size();
        visited[x][y]=1;

        for(int i=0;i<4;i++){
            int xc=x+X[i];
            int yc=y+Y[i];

            if(xc>=0 && xc<n && yc>=0 && yc<m && grid[xc][yc] && !visited[xc][yc]){
                dfs(grid,xc,yc,visited,X,Y);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};
        
        for(int i=0;i<n;i++){

            //first column
            if(grid[i][0] && !visited[i][0]){
                dfs(grid,i,0,visited,X,Y);
            }

            //last column
            if(grid[i][m-1] && !visited[i][m-1]){
                dfs(grid,i,m-1,visited,X,Y);
            }
        }

        for(int i=0;i<m;i++){

            //first row
            if(grid[0][i] && !visited[0][i]){
                dfs(grid,0,i,visited,X,Y);
            }

            //last row
            if(grid[n-1][i] && !visited[n-1][i]){
                dfs(grid,n-1,i,visited,X,Y);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]) ans++;
            }
        }

        return ans;
}


//Done using BFS 
//Time complexity--->O(n*m)
//Space complexity--->O(n*m)
int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){

            //first column
            if(grid[i][0]){
                q.push({i,0});
                visited[i][0]=1;
            }

            //last column
            if(grid[i][m-1]){
                q.push({i,m-1});
                visited[i][m-1]=1;
            }
        }

        for(int i=0;i<m;i++){

            //first row
            if(grid[0][i]){
                q.push({0,i});
                visited[0][i]=1;
            }

            //last row
            if(grid[n-1][i]){
                q.push({n-1,i});
                visited[n-1][i]=1;
            }
        }


        int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int xc=x+X[i];
                int yc=y+Y[i];

                if(xc>=0 && xc<n && yc>=0 && yc<m && grid[xc][yc] && !visited[xc][yc]){
                    q.push({xc,yc});
                    visited[xc][yc]=1;
                }
            }
        }


        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]) ans++;
            }
        }

        return ans;
    }