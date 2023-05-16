#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

//Time complexity for addRightBoundary--->O(h), where h is the height of the treed
//Time complexity for addLeftBoundary--->O(h), where h is the height of the treed
//Time complexity for addLeaves--->O(n)
//Space complexity-->O(n)

bool isLeaf(Node*root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }

    void addRightBoundary(Node*root,vector<int>&ans){
        stack<int>st;
        Node*temp=root->right;
        while(temp){
            if(!isLeaf(temp)) st.push(temp->data);
            if(temp->right!=NULL) temp=temp->right;
            else temp=temp->left;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    void addLeftBoundary(Node*root,vector<int>&ans){
        Node*temp=root->left;
        while(temp){
            if(!isLeaf(temp)) ans.push_back(temp->data);
            if(temp->left!=NULL) temp=temp->left;
            else temp=temp->right;
        }
    }
    void addLeaves(Node*root,vector<int>&ans){
        
        if(root==NULL) return;
        if(isLeaf(root)) ans.push_back(root->data);
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root,ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);
        return ans;
        
        
    }