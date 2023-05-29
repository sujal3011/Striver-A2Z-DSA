#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid,vector<vector<int>> &visited,vector<pair<int,int>> &v,int x,int y,int baseX,int baseY,int X[],int Y[]){
        int n=grid.size(),m=grid[0].size();
        visited[x][y]=1;
        v.push_back({x-baseX,y-baseY});
        
        for(int i=0;i<4;i++){
            int xc= x + X[i];
            int yc= y + Y[i];
            if(xc>=0 && xc<n && yc>=0 && yc<m && !visited[xc][yc] && grid[xc][yc]==1){
                dfs(grid,visited,v,xc,yc,baseX,baseY,X,Y);
            }
            
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int X[]={-1,0,+1,0};
        int Y[]={0,+1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(grid,visited,v,i,j,i,j,X,Y);
                    st.insert(v);
                }
            }
        }
        
        return st.size();
}