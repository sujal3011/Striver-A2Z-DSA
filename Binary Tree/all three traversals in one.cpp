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


//All three traversals using a single stack
//Time complexity---O(3*n)
//Space complexity-->O(4*n)
void preInPost(TreeNode*root){
    stack<pair<TreeNode*,int>>st;
    vector<int>pre,in,post;
    st.push({root,1});
    while(!st.empty()){
        root=st.top().first;
        int num=st.top().second;
        st.pop();

        if(num==1){
            pre.push_back(root->val);
            st.push({root,num+1});
            if(root->left!=NULL) st.push({root->left,1});
        }

        else if(num==2){
            in.push_back(root->val);
            st.push({root,num+1});
            if(root->right!=NULL) st.push({root->right,1});
        }

        else{
            post.push_back(root->val);
        }

    }
}