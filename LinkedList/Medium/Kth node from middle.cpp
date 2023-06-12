#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Better approach
//Time complexity--->O(n) + O(n/2+1-B)
//Space complexity--->O(1)
int countLength(ListNode*A){
    int cnt=0;
    ListNode*temp=A;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
int solve(ListNode* A, int B) {
   int nodes=countLength(A);
   int node_from_start=nodes/2+1-B;
   if(node_from_start<=0) return -1;
   ListNode*temp=A;
   for(int i=0;i<node_from_start-1;i++){
       temp=temp->next;
   }
   return temp->val;
    
}


//Better approach
//Combining the login to find middle node using two pointers and kth node from end
// In one traversal
//Time complexity--->O(n)
//Space complexity--->O(1)
int solve(ListNode* A, int B) {
    if(A->next==NULL) return -1;
    ListNode*p1=A,*p3=A;
    for(int i=0;i<B-1;i++){
        p1=p1->next;
        p3=p3->next->next;
        if(p3==NULL || p3->next==NULL) return -1;
    }
    p1=p1->next;
    p3=p3->next->next;
    ListNode*p2=A;
    while(p3!=NULL && p3->next!=NULL){
        p1=p1->next;
        p2=p2->next;
        p3=p3->next->next;
    }
    return p2->val; 
}