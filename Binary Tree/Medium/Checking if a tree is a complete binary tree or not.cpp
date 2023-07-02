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


//Using level order traversal (BFS)
//Time complexity-->O(N+E)-->O(N)
//Time complexity-->O(N)
//https://youtu.be/olbiZ-EOSig
 bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
            else{
                while(!q.empty()){
                    if(q.front()!=NULL) return false;
                    else q.pop();
                }
            }
        }

        return true;
        
}

//Using DFS
//Time complexity-->O(N+E)-->O(N)
//Time complexity-->O(N)
int countNodes(TreeNode*root){
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            cnt++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return cnt;
    }

    bool checkCompleteTree(TreeNode*root,int idx,int n){

        if(root==NULL) return true;
        if(idx>=n) return false;
        return checkCompleteTree(root->left,2*idx+1,n) && checkCompleteTree(root->right,2*idx+2,n);
    }
    bool isCompleteTree(TreeNode* root) {

        int nodeCount=countNodes(root);
        return checkCompleteTree(root,0,nodeCount);


        
    }