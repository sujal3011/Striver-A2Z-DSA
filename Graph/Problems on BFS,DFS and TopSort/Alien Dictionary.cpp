#include<bits/stdc++.h>
using namespace std;

//Using TopoSort
vector<int> topoSort(int V, vector<vector<int>> &adj) 
	{
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	         if(indegree[i]==0) q.push(i);
	    }
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto child:adj[node]){
	            indegree[child]--;
	            if(indegree[child]==0) q.push(child);
	        }
	        
	    }
	    return topo;
	     
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>>adj(K);
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int j=0;
            while(j<s1.length() && j<s2.length()){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
                else j++;
            }
        }
        
        vector<int>topo=topoSort(K,adj);
        string ans="";
        for(auto it:topo){
            ans+= char(it + 'a');
        }
        return ans;
        
        
}