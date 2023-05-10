#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// (Brute force)
//Time complexity--->O(n)
//Space complexity--->O(n)

bool isPalindrome(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=arr.size()-1;
        while(i<=j){
            if(arr[i]!=arr[j]) return false;
            i++;
            j--;
        }
        return true;
}

// (Optimized approach)
//Time complexity--->O(n/2)+O(n/2)+O(n/2)
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


    bool isPalindrome(ListNode* head) {

        //Finding middle of the list--->O(n/2)
        ListNode*prev=head;
        ListNode*curr=head;
        while(curr!=NULL && curr->next!=NULL){
            prev=prev->next;
            curr=curr->next->next;
        }

        //Reversing the secondhalf of the list--->O(n/2)
        ListNode*rf=reverseList(prev);

        //Checking for palindrome--->O(n/2)
        curr=head;
        while(curr!=prev){
            if(curr->val!=rf->val) return false;
            curr=curr->next;
            rf=rf->next;
        }
        return true;
}


int main(){

    return 0;
}
