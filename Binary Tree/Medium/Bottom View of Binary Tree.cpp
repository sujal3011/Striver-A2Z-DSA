#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

//Time complexity--->O(n)
//Space complexity-->O(n)
//Uisng level order traversal
vector<int> bottomView(Node *root)
    {
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int vt=it.second;
            Node*node=it.first;
            mp[vt]=node->data;
            if(node->left) q.push({node->left,vt-1});
            if(node->right) q.push({node->right,vt+1});
        }
        vector<int>ans;
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;     
        
}