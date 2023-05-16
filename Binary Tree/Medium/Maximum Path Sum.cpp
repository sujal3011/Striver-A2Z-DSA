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


//Time complexity---O(n)

int maxPath(TreeNode* root,int &ans){

       if(root==NULL) return 0;

       int left=maxPath(root->left,ans);
       int right=maxPath(root->right,ans);

       ans=max(ans,root->val+left+right);
       
       int res=root->val+max(left,right);
       if(res>0) return res;
       return 0;
}
    
int maxPathSum(TreeNode* root) {
    int ans=INT_MIN;
    maxPath(root,ans);
    return ans;
}

int main(){

    return 0;
}