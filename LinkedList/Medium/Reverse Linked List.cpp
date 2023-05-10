#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Iterative approach
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode* reverseList(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
}

//Recursive approach
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;

        ListNode*temp1=reverseList(head->next);
        ListNode*temp2=temp1;
        while(temp2->next!=NULL) temp2=temp2->next;
        temp2->next=head;
        head->next=NULL;
        return temp1; 
}

int main(){

    return 0;
}

//DP Solutions

