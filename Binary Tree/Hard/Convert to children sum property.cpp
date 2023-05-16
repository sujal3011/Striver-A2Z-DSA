//Convert an arbitrary Binary Tree to one that holds the Children Sum Property in its Nodes

#include<bits/stdc++.h>
using namespace std;
 
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
     
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//Brute force
//Time complexity-->O(n^2)
//Space complexity--->O(n)
void convertTree(Node*root){
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;

    convertTree(root->left);
    convertTree(root->right);

    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;
    int diff=sum-root->data;
    if(diff>0){
        root->data+=diff;
    }
    else if(diff<0){
       increment(root,diff); 
    }

}

void increment(Node* Node, int diff)
{
    /* IF left child is not
    NULL then increment it */
    if(Node->left != NULL)
    {
        Node->left->data = Node->left->data + diff;
     
        // Recursively call to fix
        // the descendants of Node->left
        increment(Node->left, diff);
    }
    else if (Node->right != NULL) // Else increment right child
    {
        Node->right->data = Node->right->data + diff;
     
        // Recursively call to fix
        // the descendants of Node->right
        increment(Node->right, diff);
    }
}

//Optimized solution
//Time complexity-->O(n)
//Space complexity--->O(n)
int fixTree(Node* &root){
		
		if(root==NULL)  return 0;
		if((root->left==NULL && root->right==NULL)) return root->data;
		 int sum=0;
	    if(root->left) sum+=root->left->data;
	    if(root->right) sum+=root->right->data;
	    if(sum<root->data){
	    	if(root->left) root->left->data=root->data;
	    	if(root->right) root->right->data=root->data;
	    }
	    else if(sum>root->data){
	       root->data=sum; 
	    }
	    
	    root->data=fixTree(root->left)+fixTree(root->right);
	    return root->data;
	}
	void fixBinaryTree(Node* &root)
	{
		
	    fixTree(root);
	}