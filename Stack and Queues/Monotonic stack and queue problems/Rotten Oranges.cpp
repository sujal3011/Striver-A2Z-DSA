#include<bits/stdc++.h>
using namespace std;


//Optimal approach
//BFS
//Time complexity---O(n*m)
//Space complexity-->O(n*m)
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue <pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }
            }
        }
        int time=0;
        vector<int>row_diff={0,-1,0,1};
        vector<int>col_diff={-1,0,1,0};
        while(!q.empty()){
            int x=q.front().second.first;
            int y=q.front().second.second;
            int ct=q.front().first;
            q.pop();
            time=max(time,ct);
            for(int i=0;i<4;i++)
            {
                int x_new=x+row_diff[i];
                int y_new=y+col_diff[i];

                if(x_new>=0 && x_new<n && y_new>=0 && y_new<m && grid[x_new][y_new]==1 && vis[x_new][y_new]!=2){
                    vis[x_new][y_new]=2;
                    q.push({ct+1,{x_new,y_new}});
                }

            }
            
        }

        //checking whether all the fresh oranges have rottened or not
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2) return -1;
            }
        }

        return time;
}

int main(){

    return 0;
}