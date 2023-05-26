#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(V + 2E)
//Time complexity--->O(N) + O(N),for visited array and recursive stack space in worst case
void dfs(vector<int>adj[], int node, vector<int> &visited, vector<int> &ans){
        visited[node]=1;
        ans.push_back(node);
        for(auto child:adj[node]){
            if(!visited[child]) dfs(adj,child,visited,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        vector<int>ans;
        dfs(adj,0,visited,ans);
        return ans;
    }

