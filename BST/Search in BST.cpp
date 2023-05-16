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


//Time complexity-->O(h)
//Space complexity--->O(1)
TreeNode* searchBST(TreeNode* root, int val) {
      while(root!=NULL && root->val!=val){
          root= root->val>val ? root->left : root->right; 
      }
      return root;
}