#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        if(rank[ulp_u]==rank[ulp_v]){
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {

        int m=connections.size();
        DisjointSet ds(n);
        int extra_edges=0;
        for(int i=0;i<m;i++){
            int u=connections[i][0],v=connections[i][1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                extra_edges++;
            }
            else{
                ds.unionBySize(u,v);
            }      
        }
        int cc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cc++;
        }

        if(extra_edges>=cc-1) return cc-1;
        return -1;      
    }
};