#include<bits/stdc++.h>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

//Time complexity-->O(nlogn)
//Space complexity-->O(n),space taken by map and queue
//Here we are using level order traversal for traversing
vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<pair<pair<TreeNode*,int>,int>>q;
        map<int,map<int,multiset<int>>>mp;

        q.push({{root,0},0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode*node=it.first.first;
            int vt=it.first.second;
            int lvl=it.second;
            mp[vt][lvl].insert(node->val);
            if(node->left!=NULL) q.push({{node->left,vt-1},lvl+1});
            if(node->right!=NULL) q.push({{node->right,vt+1},lvl+1});
        }

        vector<vector<int>>ans;
        for(auto p:mp){
            vector<int>temp;
            for(auto q:p.second){
                for(auto r:q.second){
                    temp.push_back(r);
                }
            }
            ans.push_back(temp);
        }
        return ans;
}

//Time complexity-->O(nlogn)
//Space complexity-->O(n),recursive stack space and space taken by the map
//Here we are using preorder traversal for traversing
void inOrder(map<int,map<int,multiset<int>>> &mp,TreeNode*root,int vt,int lvl){

        if(root==NULL) return;
         mp[vt][lvl].insert(root->val);

        inOrder(mp,root->left,vt-1,lvl+1);
        inOrder(mp,root->right,vt+1,lvl+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
        map<int,map<int,multiset<int>>>mp;
        inOrder(mp,root,0,0);
       
        vector<vector<int>>ans;
        for(auto p:mp){
            vector<int>temp;
            for(auto q:p.second){
                for(auto r:q.second){
                    temp.push_back(r);
                }
            }
            ans.push_back(temp);
        }
        return ans;
}


};