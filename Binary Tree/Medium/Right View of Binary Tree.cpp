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
//Uisng level order traversal
vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode*node=it.first;
            int lvl=it.second;
            mp[lvl]=node->val;
            if(node->left) q.push({node->left,lvl+1});
            if(node->right) q.push({node->right,lvl+1});
        }

        for(auto it:mp) ans.push_back(it.second);
        return ans;
}

//Time complexity--->O(n)
//Space complexity-->O(n)
//Uisng recursive traversal (preorder)
void preOrder(TreeNode*root,map<int,int> &mp,int lvl){

        if(root==NULL) return;

        mp[lvl]=root->val;
        preOrder(root->left,mp,lvl+1);
        preOrder(root->right,mp,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>mp;
        preOrder(root,mp,0);
        for(auto it:mp) ans.push_back(it.second);
        return ans;

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