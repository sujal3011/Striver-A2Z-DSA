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


//Brute force approach
//Finding the path of both the nodes from the root
//Using extra space to store the paths
//Time complexity--->O(n)
//Space complexity-->O(n)
bool isPath(TreeNode*root,int x,vector<TreeNode*> &ans){
    
        if(root==NULL) return false;
        
        ans.push_back(root);
        if(root->val==x) return true;
        if(isPath(root->left,x,ans) || isPath(root->right,x,ans)) return true;
        ans.pop_back();
        return false;
    }
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>A,B;
        isPath(root,p->val,A);
        isPath(root,q->val,B);
        int i=min(A.size(),B.size())-1;
        while(i>=0){
            if(A[i]->val==B[i]->val) break;
            i--;
        }
        return A[i];
}

//Optimized solution
//Not using any extra space
//Time complexity--->O(n)
//Space complexity-->O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;

        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        if(left!=NULL) return left;
        return right;

    }