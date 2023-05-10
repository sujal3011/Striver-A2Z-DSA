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


//Recursive solution
//Time complexity---O(n)
//Space complexity-->O(n)
void preOrder(TreeNode*root,vector<int>&ans){
    
    if(root==NULL) return;
  
  ans.push_back(root->val);
  preOrder(root->left,ans);
  preOrder(root->right,ans);
  
}

vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrder(root,ans);
        return ans;
}


//Iterative solution
//Using stack
//Time complexity---O(n)
//Space complexity-->O(n)
vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*node=st.top();
            st.pop();
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
            ans.push_back(node->val);
        }

        return ans;

    }

int main(){

    return 0;
}