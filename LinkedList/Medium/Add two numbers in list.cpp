#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach-1
//Creating a new resultant linked list
//Time complexity--->O(n+m)
//Space complexity--->O(n+m)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode(0);
        dummy->next=NULL;
        ListNode*temp=dummy;
        int sum=0,carr=0;
        while(l1!=NULL || l2!=NULL || carr!=0){
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carr;
            carr=sum/10;
            ListNode*node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
            sum=0;
        }
        return dummy->next;
}


//Approach-2
//Updating the result in the longer linked list
//Time complexity--->O(n+m)
//Space complexity--->O(1)
 ListNode*insertAtEnd(ListNode*head,int data){
        if(head==NULL) return NULL;
        ListNode*temp=head;
        ListNode*newnode=new ListNode(data);
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newnode;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*a=l1,*b=l2;
        int carry=0,n=0,m=0;
        while(a!=NULL || b!=NULL){
            if(a!=NULL){
                n++;
                a=a->next;
            }
            if(b!=NULL){
                m++;
                b=b->next;
            }
        }

        a=l1,b=l2;
        while(a!=NULL && b!=NULL){
            int sum=a->val+b->val+carry;
            int r=sum%10;
            carry=sum/10;
            if(n>=m) a->val=r;
            else b->val=r;
            a=a->next;
            b=b->next;

        }
        if(a==NULL && b==NULL){
            if(carry!=0) l1=insertAtEnd(l1,carry); 
        }
        else if(a==NULL){
            while(b!=NULL && (b->val+carry)>9){
                int x=b->val+carry;
                int rem=x%10;
                carry=x/10;
                b->val=rem;
                b=b->next;
            }
            if(b!=NULL){
                b->val+=carry;
            }
            else{
                l2=insertAtEnd(l2,carry);
            }
        }

        else{
            while(a!=NULL && (a->val+carry)>9){
                int x=a->val+carry;
                int rem=x%10;
                carry=x/10;
                a->val=rem;
                a=a->next;
            }
            if(a!=NULL){
                a->val+=carry;
            }
            else{
                l1=insertAtEnd(l1,carry);
            }
        }

        if(n>=m) return l1;
        return l2;


    }
