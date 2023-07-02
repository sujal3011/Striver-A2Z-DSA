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
//Same as sort a list of 0's and 1's
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode* partition(ListNode* A, int B) {
    ListNode*dummy1=new ListNode(0);
    ListNode*dummy2=new ListNode(0);
    ListNode*temp1=dummy1;
    ListNode*temp2=dummy2;
    ListNode*temp=A;
    while(temp!=NULL){
        if(temp->val<B){
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
