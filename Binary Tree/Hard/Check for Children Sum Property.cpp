#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


//Time complexity--->O(n)
//Space complexity-->O(n)
bool isSum(Node*root){
        
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        
        int sum=0;
        if(root->left) sum+=root->left->data;
        if(root->right) sum+=root->right->data;
        if((root->data)!=sum) return false;
        bool left=isSum(root->left);
        bool right=isSum(root->right);
        return (left && right);
    }
    int isSumProperty(Node *root)
    {
        return isSum(root);
    }