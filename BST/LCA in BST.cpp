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


//Iterative solution
//Time complexity--->O(H)
//Space complexity-->O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(1){
            if(root->val<p->val && root->val<q->val) root=root->right;
            else if(root->val>p->val && root->val>q->val) root=root->left;
            else break;

        }
        return root;
}

//Recursive solution
//Time complexity--->O(H)
//Space complexity-->O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(1){
            if(root->val<p->val && root->val<q->val) root=root->right;
            else if(root->val>p->val && root->val>q->val) root=root->left;
            else break;

        }
        return root;
}