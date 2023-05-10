#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Naive approach (Traversing 2 times)
//Time complexity--->O(n) + O(n) =O(2*n)
//Space complexity--->O(1)

ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int x=cnt-n+1;
        if(x==1){
            ListNode*temp=head->next;
            delete head;
            return temp;
        }
        temp=head;
        for(int i=0;i<x-2;i++){
            temp=temp->next;
        }
        ListNode*temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;

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
