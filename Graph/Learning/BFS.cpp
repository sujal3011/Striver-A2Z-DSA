#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        queue<int>q;
        vector<int>visited(V,0);
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto child:adj[node]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=1;
                }
            }
            
        }
        return ans;
}