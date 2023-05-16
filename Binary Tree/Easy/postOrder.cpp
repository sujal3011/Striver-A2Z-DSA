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
 void postOrder(TreeNode*root,vector<int>&ans){
    
    if(root==NULL) return;
  
    postOrder(root->left,ans);
    postOrder(root->right,ans);
    ans.push_back(root->val);
  
}

vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postOrder(root,ans);
        return ans;
}


//Iterative solution-1
//Using 2 stack
//Time complexity---O(n)
//Space complexity-->O(2*n)
vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st1,st2;
        TreeNode*node=root;
        st1.push(root);
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
            st2.push(node);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }

int main(){

    return 0;
}