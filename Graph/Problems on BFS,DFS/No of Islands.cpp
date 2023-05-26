#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid,int n,int m,vector<vector<int>>& visited,int i,int j,int X[],int Y[]){
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int xi=i+X[k];
            int yi=j+Y[k];
            if(xi>=0 && xi<n && yi>=0 && yi<m  && grid[xi][yi]=='1' && !visited[xi][yi]){
                dfs(grid,n,m,visited,xi,yi,X,Y);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt=0;
        int X[]={0,-1,0,+1};
        int Y[]={-1,0,+1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cnt++;
                    dfs(grid,n,m,visited,i,j,X,Y);
                }
            }
        }

        return cnt;

}