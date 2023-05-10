#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//merge Sort
//Time complexity--->O(nlogn)
//Space complexity--->O(1)

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode*l1,*l2;
        if(list1->val<=list2->val){
            l1=list1;
            l2=list2;
        }
        else{
            l1=list2;
            l2=list1;
        }
        ListNode*res=l1;
        ListNode*temp=NULL;
        while(l1!=NULL){
            if(l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                ListNode*temp2=l1;
                l1=l2;
                l2=temp2;
                temp=NULL;

            }
        }
        temp->next=l2;
        return res;


    }

//This middleNode function returns the first middle node in case of even number of nodes
ListNode* middleNode(ListNode* head) {
        ListNode*prev=head;
        ListNode*curr=head;
        while(curr->next!=NULL && curr->next->next!=NULL){
            prev=prev->next;
            curr=curr->next->next;
        }
        return prev;
}

ListNode*mergeSort(ListNode*head){

        if(head==NULL || head->next==NULL) return head;

        //Finding the middle node
        ListNode*mid=middleNode(head);

        //Dividing the list into two halves
        ListNode*left=head;
        ListNode*right=mid->next;
        mid->next=NULL;

        //recursively calling the mergeSort function for the two halves
        left=mergeSort(left);
        right=mergeSort(right);

        //merging the two sorted halves
        return mergeTwoLists(left,right);



}

ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    
}


int main(){

    return 0;
}
