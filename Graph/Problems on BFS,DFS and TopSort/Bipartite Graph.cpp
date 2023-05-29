
#include<bits/stdc++.h>
using namespace std;

//This function will check for one component
bool checkBipartite(vector<vector<int>>& graph,int start,vector<int> &colour){

        queue<int>q;
        q.push(start);
        colour[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto child:graph[node]){
                if(colour[child]==-1){
                    q.push(child);
                    colour[child]=!colour[node];
                }
                else if(colour[child]==colour[node]) return false;   
            }
        }

        return true;
}

//Using BFS
//TC and SC same as BFS
bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
         vector<int>colour(n,-1);

        //Checking for multiple components
        for(int i=0;i<n;i++){
             if(colour[i]==-1 && checkBipartite(graph,i,colour)==false){
                 return false;
             }
        }

        return true;
}


//Using DFS
//TC and SC same as DFS
bool dfs(vector<vector<int>>& graph,int node,int nodeColour,vector<int> &colour){
        colour[node]=nodeColour;
        bool flag=true;
        for(auto child:graph[node]){
            if(colour[child]==-1){
                if(dfs(graph,child,!nodeColour,colour)==false) flag=false;
            }
            else if(colour[child]==colour[node]) flag=false;
        }
        return flag;
}

bool isBipartite(vector<vector<int>>& graph) {

         int n=graph.size();
         vector<int>colour(n,-1);

        //Checking for multiple components
        for(int i=0;i<n;i++){
             if(colour[i]==-1 && dfs(graph,i,0,colour)==false){
                 return false;
             }
        }

        return true;
}