//Convert an arbitrary Binary Tree to one that holds the Children Sum Property in its Nodes

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Time complexity-->O(n)
//Space complexity--->O(n)
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*,int>visited;
        q.push(target);
        visited[target]=1;
        int dis=0;
        while(dis<k){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                if(parent.find(node)!=parent.end() && visited.find(parent[node])==visited.end()){
                   visited[parent[node]]=1;
                   q.push(parent[node]);
                }
                if(node->left && visited.find(node->left)==visited.end()){
                    visited[node->left]=1;
                    q.push(node->left);
                } 
                if(node->right && visited.find(node->right)==visited.end()){
                    visited[node->right]=1;
                    q.push(node->right);
                } 
            }
            dis++;
        }

        cout<<q.size()<<endl;

        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;

}