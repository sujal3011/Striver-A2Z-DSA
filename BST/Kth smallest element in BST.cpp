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


//Brute force approach
//Time complexity-->O(n) + (nlogn)
//Space complexity--->O(n)
void inOrder(TreeNode*root,vector<int> &nodes){
        if(root==NULL) return;
        inOrder(root->left,nodes);
        nodes.push_back(root->val);
        inOrder(root->right,nodes);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>nodes;
        inOrder(root,nodes);
        sort(nodes.begin(),nodes.end());
        return nodes[k-1];
}


//Better
//Time complexity-->O(n)
//Space complexity--->O(n),(external space used)
void inOrder(TreeNode*root,vector<int> &nodes){
        if(root==NULL) return;
        inOrder(root->left,nodes);
        nodes.push_back(root->val);
        inOrder(root->right,nodes);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>nodes;
        inOrder(root,nodes);
        return nodes[k-1];
}


//Most optimized
//Time complexity-->O(n)
//Space complexity--->O(n),only for the recursive stack space (no external space used)
void inOrder(TreeNode*root,int &cnt,int k,int &ans){
        if(root==NULL) return;
        inOrder(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k) ans=root->val;
        inOrder(root->right,cnt,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0, ans=-1;
        inOrder(root,cnt,k,ans);
        return ans;
    }