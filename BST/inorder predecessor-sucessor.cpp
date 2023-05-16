#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int key;
	struct Node *left, *right;
};


//Brute appraoch
//Time complexity--->O(n)+O(logn)
//Space complexity--->O(n)

//Better appraoch
//Time complexity--->O(n)
//Space complexity--->O(1)

//Optimized approach
//Time complexity--->O(H)
//Space complexity--->O(1)

void findPre(Node*root,Node*&pre,int key){
    Node*temp=root;
    while(temp!=NULL){
    if(temp->key>=key) temp=temp->left;
    else {
       pre=temp;
       temp=temp->right;
    }  
    }
    
}

void findSuc(Node*root,Node*&suc,int key){
    Node*temp=root;
    while(temp!=NULL){
    if(temp->key<=key) temp=temp->right;
    else {
       suc=temp;
       temp=temp->left;
    }  
    }
    
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
  pre=NULL,suc=NULL;
  findPre(root,pre,key);
  findSuc(root,suc,key);
  

}