#include<bits/stdc++.h>
using namespace std;

//Application of Floyd Warshall algorithm
//Time complexity--->O(n^3)
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