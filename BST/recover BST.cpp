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




//Brute force
//Time complexity-->O(n) + O(nlogn)
//Space complexity--->O(n),external space
void traversal(TreeNode*root,vector<int>&in){
        if(root==NULL) return;
        traversal(root->left,in);
        in.push_back(root->val);
        traversal(root->right,in);
    }
    void inOrder(TreeNode* &root,vector<int>&in,int &i){
        if(root==NULL) return;
        inOrder(root->left,in,i);
        if(in[i]!=root->val) root->val=in[i];
        i++;
        inOrder(root->right,in,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>in;
        traversal(root,in);
        sort(in.begin(),in.end());
        for(auto x:in) cout<<x<<" ";
        cout<<endl;
        int i=0;
        inOrder(root,in,i);
}
   


//Optimized approach
//Time complexity-->O(n)
//Space complexity--->O(n),only for the recursive stack space (no external space used)
class Solution {
private:
    TreeNode*first;
    TreeNode*middle;
    TreeNode*last;
    TreeNode*prev;
public:
    void inOrder(TreeNode*root){
        if(root==NULL) return;
        inOrder(root->left);

        if(prev!=NULL && root->val<prev->val){

            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=middle=last=prev=NULL;
        inOrder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};