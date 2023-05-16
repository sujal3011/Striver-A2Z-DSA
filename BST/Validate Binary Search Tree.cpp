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




//Appraoch-1
//Time complexity-->O(n)
//Space complexity--->O(n),only for the recursive stack space
pair<bool,pair<int,int>>isBST(TreeNode*root){
        if(root==NULL) return {true,{INT_MAX,INT_MIN}};
        if(root->left==NULL && root->right==NULL) return {true,{root->val,root->val}};
        auto it1=isBST(root->left);
        auto it2=isBST(root->right);
        bool flag=1;
        if(it1.first && it2.first){
            if(root->left){
                if(root->val<=it1.second.second) flag=0;
            }
            if(root->right){
                if(root->val>=it2.second.first) flag=0;
            } 
        }
        else flag=0;
    
        if(flag) return {true,{min(it1.second.first,root->val),max(root->val,it2.second.second)}};
        return {false,{0,0}};

}
    bool isValidBST(TreeNode* root) {

        return isBST(root).first;
}



//Approach 2
//Time complexity-->O(n)
//Space complexity--->O(n),only for the recursive stack space (no external space used)
bool isBST(TreeNode*root,long long left_range,long long right_range){
        if(root==NULL) return true;
        if(root->val<=left_range || root->val>=right_range) return false;
        return ( isBST(root->left,left_range,root->val) && isBST(root->right,root->val,right_range));
}
bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
}