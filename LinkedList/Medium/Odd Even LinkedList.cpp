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

 ListNode* oddEvenList(ListNode* head) {

        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;

        //counting the number of nodes in the list
        ListNode*temp=head;
        int cnt=1;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
        ListNode*end=temp;
        temp=head;

        //At every iteration of the loop the temp is pointing to a node which is present at odd position in the original list,so the node after the temp node is present at even position in the list and so it is being moved to the end of the list
        for(int i=0;i<cnt/2;i++){
            end->next=temp->next;
            temp->next=temp->next->next;
            end->next->next=NULL;
            temp=temp->next;
            end=end->next;
        }
        return head;
}

//Appraoch 2
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;

        ListNode*oh=head,*odd=head;
        ListNode*eh=head->next,*even=head->next;

        //Dividing the given list into two different lists,one containing nodes at odd position and the other containing nodes at even position
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        //Reconnecting the two lists
        odd->next=eh;
        return oh;
        
}


int main(){

    return 0;
}
