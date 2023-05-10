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

//Approach-1
//Changing links
//Time complexity--->O(n)
//Space complexity--->O(1)
Node* segregate(Node *head) {
        
        //counting the number of 1's and 2's
        int one_cnt=0,two_cnt=0;
        Node*temp=head;
        while(temp!=NULL){
            if(temp->data==1) one_cnt++;
            else if(temp->data==2) two_cnt++;
            temp=temp->next;
        }
        
        Node*dummy=new Node(-1);
        //moving all the nodes with 1 as data to the end of the list
        dummy->next=head;
        Node*d1=dummy;
        Node*d2=head;
        Node*end=head;
        while(end->next!=NULL) end=end->next;
        int i=0;
        while(d2!=NULL && i<one_cnt){
            if(d2->data==1){
                i++;
                end->next=d2;
                d1->next=d2->next;
                d2=d2->next;
                end->next->next=NULL;
                end=end->next;
            }
            else{
                d1=d1->next;
                d2=d2->next;
            }
        }

        //moving all the nodes with 2 as data to the end of the list
        i=0;
        d1=dummy,d2=dummy->next;
       while(d2!=NULL && i<two_cnt){
            if(d2->data==2){
                i++;
                end->next=d2;
                d1->next=d2->next;
                d2=d2->next;
                end->next->next=NULL;
                end=end->next;
            }
            else{
                d1=d1->next;
                d2=d2->next;
            }
        }
        
        return dummy->next;
}


//Approach-2
//Changing data
//Time complexity--->O(n)
//Space complexity--->O(1)
Node* segregate(Node *head) {
        
        vector<int>cnt(3,0);
        Node*temp=head;
        while(temp!=NULL){
            if(temp->data==0) cnt[0]++;
            else if(temp->data==1) cnt[1]++;
            else cnt[2]++;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<cnt[0];i++){
            temp->data=0;
            temp=temp->next;
        }
        for(int i=0;i<cnt[1];i++){
            temp->data=1;
            temp=temp->next;
        }
        for(int i=0;i<cnt[2];i++){
            temp->data=2;
            temp=temp->next;
        }
        
        return head;
}