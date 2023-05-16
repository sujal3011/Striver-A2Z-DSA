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
bool isPath(TreeNode*root,int x,vector<int> &ans){
    
    if(root==NULL) return false;
    
    ans.push_back(root->val);
    if(root->val==x) return true;
    if(isPath(root->left,x,ans) || isPath(root->right,x,ans)) return true;
    ans.pop_back();
    return false;
}
vector<int>solve(TreeNode* A, int B) {
    vector<int>ans;
    if(isPath(A,B,ans)) return ans;    
}
