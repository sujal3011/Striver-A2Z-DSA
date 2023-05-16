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


//Time complexity--->O(n)
//Space complexity-->O(n)
//Recursive solution
 bool checkSymmetric(TreeNode*left,TreeNode*right){

        if(left==NULL || right==NULL) return left==right;

        if(left->val!=right->val) return false;
        if(checkSymmetric(left->left,right->right) && checkSymmetric(left->right,right->left)) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left,root->right);
        
}

//OPTIMIZED SOLUTION
//REVERSE PREORDER
//Time complexity--->O(n)
//Space complexity-->O(1)
//Uisng recursive traversal (preorder)
void ReversepreOrder(TreeNode*root,vector<int> &ans,int lvl){

        if(root==NULL) return;
        if(lvl==ans.size()) ans.push_back(root->val);  //IMPORTANT--->this checks whether we are visiting the level for the first time or not
        ReversepreOrder(root->right,ans,lvl+1);
        ReversepreOrder(root->left,ans,lvl+1);
    }
vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        ReversepreOrder(root,ans,0);
        return ans;

}


//Iterative solution
//Using 2 stacks
//Can be optimized to do using 1 stack only