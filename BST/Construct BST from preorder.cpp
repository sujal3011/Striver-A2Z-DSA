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

//Brute appraoch
//Traversing through all the elements of the preorder and keep inserting the elements in the BST 
//Time complexity--->O(n square)
//Space complexity--->O(1)

 TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*temp=root;
        TreeNode*node=new TreeNode(val);
        if(root==NULL) return node;
        
        while(1){
            if(temp->val>val){
                if(temp->left==NULL) break;
                else temp=temp->left;
            }
            else{
                if(temp->right==NULL) break;
                temp=temp->right;
            }
        }
        if(val<temp->val) temp->left=node;
        else temp->right=node;

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=NULL;
        for(int x:preorder) root=insertIntoBST(root,x);
        return root;
    }


//Better approach
//Time complexity--->O(n) +  O(nlogn)
//Space complexity--->O(n),recursive stack space and space for map

TreeNode * constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode * root = new TreeNode(preorder[preStart]);
  int elem = mp[root -> val];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

TreeNode * buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart=  0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());  //Time complexity of O(nlogn) for sorting
        return buildTree(preorder,inorder);

}


//Optimized approach