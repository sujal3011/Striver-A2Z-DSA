#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

//Optimal approach-1
//Time complexity--->O(n)
//Space complexity--->O(1)
Node*reverseList(Node*head){
        Node*prev=NULL;
        Node*curr=head;
        while(curr!=NULL){
            Node*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
}

Node* addOne(Node *head) 
{
        Node*rev=reverseList(head);
        Node*temp=rev;
        while(temp->next!=NULL && temp->data==9){
            temp->data=0;
            temp=temp->next;
        }
        if(temp->data!=9) temp->data++;
        else{
            temp->data=0;
            Node*newnode=new Node(1);
            temp->next=newnode;
        }
        return reverseList(rev);
}