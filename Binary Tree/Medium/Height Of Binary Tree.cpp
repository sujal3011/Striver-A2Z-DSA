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


//Using level order traversal
//Time complexity---O(n)
//Space complexity-->O(w),where w is the width of the binary tree, worst case will be when the tree is a completely balanced tree

 int maxDepth(TreeNode* root) {
        int ans=0;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>level;
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            ans++;

        }
        return ans;
}

//Using recursion
//Time complexity---O(n)
//Space complexity-->O(n),recursive stack space (worst case will be when the tree becomes a skew tree,i.e. a linked list)

int maxDepth(TreeNode* root) {

        if(root==NULL) return 0;
        
        int depth_left=maxDepth(root->left);
        int depth_right=maxDepth(root->right);

        return 1+max(depth_left,depth_right);
    }

int main(){

    return 0;
}