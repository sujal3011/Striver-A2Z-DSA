#include<bits/stdc++.h>
using namespace std;

// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



//Using level order traversal
//Extending the logic for checking complete binary tree
//Time complexity---O(n) + O(n) + O(n)
//Space complexity---O(n)
bool isHeap(struct Node* tree) {
        queue<Node*>q;
        q.push(tree);
        while(!q.empty()){
            Node*node=q.front();
            q.pop();
            if(node){
                if(node->left && node->data<node->left->data) return false;
                q.push(node->left);
                if(node->right && node->data<node->right->data) return false;
                q.push(node->right);
            }
            else{
                while(!q.empty()){
                    if(q.front()) return false;
                    else q.pop();
                }
            }
        }
        
        return true;
    }


//Using level order traversal
//Extending the logic for checking complete binary tree
//Time complexity---O(n) + O(n) + O(n)
//Space complexity---O(n)
int countNodes(struct Node*root){
        int cnt=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*node=q.front();
            q.pop();
            cnt++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return cnt;
    }

    bool checkCompleteTree(struct Node*root,int idx,int n){

        if(root==NULL) return true;
        if(idx>=n) return false;
        return checkCompleteTree(root->left,2*idx+1,n) && checkCompleteTree(root->right,2*idx+2,n);
    }
    bool isCompleteTree(struct Node* root) {

        int nodeCount=countNodes(root);
        return checkCompleteTree(root,0,nodeCount);
        
    }
    
    bool checkMaxHeap(struct Node*root){
        
        if(root==NULL) return true;
        
        if(root->left && root->data<root->left->data) return false;
        if(root->right && root->data<root->right->data) return false;
        
        return checkMaxHeap(root->left) && checkMaxHeap(root->right);
        
    }
  
    bool isHeap(struct Node* tree) {
        
        if(isCompleteTree(tree) && checkMaxHeap(tree)) return true;
        return false;
    }