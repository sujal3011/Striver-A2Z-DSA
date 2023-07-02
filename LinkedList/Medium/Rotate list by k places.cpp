#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode*rotateRight(ListNode* A, int B) {
    
    int cnt=1;
    ListNode*temp=A;
    while(temp->next!=NULL){
        cnt++;
        temp=temp->next;
    }
    B=B%cnt;   //IMPORTANT STEP as B can be greeater than the length of the linked list
    temp->next=A;
    temp=A;
    for(int i=0;i<cnt-B-1;i++){
        temp=temp->next;
    }
    ListNode*newhead=temp->next;
    temp->next=NULL;
    return newhead;
    
}