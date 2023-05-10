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


//Naive approach
//Time complexity---O(n^2)

int height(TreeNode* root) {

        if(root==NULL) return 0;
        
        int depth_left=height(root->left);
        int depth_right=height(root->right);

        return 1+max(depth_left,depth_right);
    }


bool isBalanced(TreeNode*root){

    if(root==NULL) return true;

    int h_left=height(root->left);
    int h_right=height(root->right);
    if(abs(h_left-h_right)>1) return false;

    bool check_left=isBalanced(root->left);
    bool check_right=isBalanced(root->right);

    if(!check_left || !check_right) return false;
    return true;
}


//Optimal approach
//Time complexity---O(n)
int heightBalanced(TreeNode*root){

        if(root==NULL) return 0;

        int left=heightBalanced(root->left);
        int right=heightBalanced(root->right);
        if(left!=-1 && right!=-1 && abs(left-right)<=1){
            return max(left,right)+1;
        }
        return -1;

    }
bool isBalanced(TreeNode* root) {
        if(heightBalanced(root)!=-1) return true;
        return false;
}


int main(){

    return 0;
}