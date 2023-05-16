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



class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        TreeNode*temp=root;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
    }
    
    int next() {
        TreeNode*tp=st.top();
        st.pop();
        TreeNode*rt=tp->right;
        while(rt!=NULL){
            st.push(rt);
            rt=rt->left;
        }
        return tp->val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }
};