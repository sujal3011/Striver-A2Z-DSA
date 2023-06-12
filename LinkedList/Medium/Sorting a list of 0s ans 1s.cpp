#include<bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//Approach-1
//Changing links
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode* solve(ListNode* A) {
    ListNode*dummy1=new ListNode(0);
    ListNode*dummy2=new ListNode(0);
    ListNode*temp1=dummy1,*temp2=dummy2;
    ListNode*temp=A;
    while(temp!=NULL){
        if(temp->val==0){
            temp1->next=temp;
            temp1=temp1->next;
        }
        else{
            temp2->next=temp;
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    temp1->next=dummy2->next;
    temp2->next=NULL;
    return dummy1->next;
}


//Approach-2
//Changing data
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode* solve(ListNode* A) {
    int zero_cnt=0,one_cnt=0;
    ListNode*temp=A;
    while(temp!=NULL){
        if(temp->val==0) zero_cnt++;
        else one_cnt++;
        temp=temp->next;
    }
    temp=A;
    for(int i=0;i<zero_cnt;i++){
        temp->val=0;
        temp=temp->next;
    }
    for(int i=0;i<one_cnt;i++){
        temp->val=1;
        temp=temp->next;
    }
    return A;
}