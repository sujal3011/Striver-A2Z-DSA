#include<bits/stdc++.h>
using namespace std;


//Time complexity--->O(n^3)
void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
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
}