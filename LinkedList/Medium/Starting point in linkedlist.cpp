#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Using hashmap
//Time complexity--->O(n)
//Space complexity--->O(n)

ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mm;
        ListNode*temp=head;
        while(temp!=NULL){
            if(mm.find(temp)!=mm.end()){
                return temp;
            }
            mm[temp]=1;
            temp=temp->next;
        }

        return NULL;
}

//Using slow and fast pointers (Optimized approach)
//Time complexity--->O(n)
//Space complexity--->O(1)
ListNode *detectCycle(ListNode *head) {

        ListNode*prev=head;
        ListNode*curr=head;
        bool flag=0;
        while(curr!=NULL && curr->next!=NULL){
            prev=prev->next;
            curr=curr->next->next;
            if(prev==curr){
                flag=1;
                break;
            }
        }
        if(!flag) return NULL;
        curr=head;
        while(prev!=curr){
            prev=prev->next;
            curr=curr->next;
        }
        return prev;
}

int main(){

    return 0;
}
