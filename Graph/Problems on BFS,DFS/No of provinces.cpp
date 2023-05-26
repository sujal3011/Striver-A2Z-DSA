#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(N) + O(V + 2E)
//Time complexity--->O(N) + O(N),for visited array and recursive stack space in worst case
void dfs(vector<int>adj[],int node,vector<int>&visited){
        visited[node]=1;
        for(auto child:adj[node]){
            if(!visited[child]) dfs(adj,child,visited);
        }

}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(adj,i,visited);
            }
        }

        return cnt;
}