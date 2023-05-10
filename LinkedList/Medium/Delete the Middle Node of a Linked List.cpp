#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Approach 1
//Time complexity--->O(n)
//Space complexity--->O(1)

 ListNode* deleteMiddle(ListNode* head) {

        if(head->next==NULL){
            return NULL;
        }

        ListNode*prev=head;
        ListNode*curr=head;
        while(curr->next->next!=NULL && curr->next->next->next!=NULL){
            prev=prev->next;
            curr=curr->next->next;
        }
        prev->next=prev->next->next;
        return head;

}

//Efficient appraoch (traversing only one time)
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode();
        dummy->next=head;
        ListNode*slow=dummy,*fast=dummy;
        for(int i=0;i<n;i++) fast=fast->next;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
}



int main(){

    return 0;
}
