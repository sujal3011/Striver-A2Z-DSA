#include<bits/stdc++.h>
using namespace std;


//BFS
//can't be done using DFS
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        int X[]={0,-1,0,+1};
        int Y[]={-1,0,+1,0};
        while(!q.empty()){
            auto it=q.front();
            int x=it.first.first;
            int y=it.first.second;
            int score=it.second;
            q.pop();
            ans[x][y]=score;
            for(int i=0;i<4;i++){
                int xc=x+X[i];
                int yc=y+Y[i];
                if(xc>=0 && xc<n && yc>=0 && yc<m && !visited[xc][yc]){
                    visited[xc][yc]=1;
                    q.push({{xc,yc},score+1});
                }
            }
        }

        return ans;
}