#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        data=val; 
        next=NULL;
        
    }

    ~Node(){
        int x=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"destructing the node with data :"<<x<<endl;   
    }
};

void InsertAtBeginning(int val,Node* &head){

    Node*newnode=new Node(val);
    newnode->next=head;
    head=newnode;
}

void InsertAtEnd(int val,Node* &head){
    if(head==NULL){
        Node*newnode=new Node(val);
        head=newnode;
        return;
    }

    Node*newnode=new Node(val);
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void deleteNode(int position,Node* &head){

    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*prev=NULL;
        Node*curr=head;
        for(int i=0;i<position-1;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void TraverseList(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){

    Node*head=NULL;
    InsertAtBeginning(10,head);
    InsertAtBeginning(20,head);
    InsertAtBeginning(40,head);
    InsertAtBeginning(50,head);
    InsertAtBeginning(80,head);
    InsertAtEnd(12,head);
    InsertAtEnd(16,head);
    TraverseList(head);
    deleteNode(4,head);
    TraverseList(head);

    return 0;
}