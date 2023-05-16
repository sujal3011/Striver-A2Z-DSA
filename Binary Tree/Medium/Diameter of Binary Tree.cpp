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


//Naive approach
//Time complexity---O(n^2)

int height(TreeNode* root) {

        if(root==NULL) return 0;
        
        int depth_left=height(root->left);
        int depth_right=height(root->right);

        return 1+max(depth_left,depth_right);
}

void findMax(TreeNode*root,int &ans){

        if(root==NULL) return;

        int l_height=height(root->left);
        int r_height=height(root->right);
        ans=max(ans,l_height + r_height);

        findMax(root->left,ans);
        findMax(root->right,ans);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        findMax(root,ans);
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