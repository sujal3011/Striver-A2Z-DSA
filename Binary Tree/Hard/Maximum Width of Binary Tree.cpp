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
int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long midx=q.front().second;
            int sz=q.size();
            long long first,last;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                TreeNode*node=it.first;
                long long curr_idx=it.second-midx;  //updated the index to prevent overflow
                if(i==0) first=curr_idx;
                if(i==(sz-1)) last=curr_idx;
                if(node->left) q.push({node->left,2*curr_idx+1});
                if(node->right) q.push({node->right,2*curr_idx+2});
            }
            ans=max(ans,last-first+1); 

        }
        return ans;
}