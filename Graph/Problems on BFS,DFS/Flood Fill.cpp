#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& image,int n,int m, int i, int j,vector<vector<int>> &visited, int color,int X[],int Y[]){
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int xi=i+X[k];
            int yi=j+Y[k];
            if(xi>=0 && xi<n && yi>=0 && yi<m && image[xi][yi]==image[i][j] && !visited[xi][yi]){
                dfs(image,n,m,xi,yi,visited,color,X,Y);
            }
        }
        image[i][j]=color;

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int X[]={0,-1,0,+1};
        int Y[]={-1,0,+1,0};
        dfs(image,n,m,sr,sc,visited,color,X,Y);
        return image;

    }