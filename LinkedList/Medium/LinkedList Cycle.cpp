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

bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mm;
        ListNode*temp=head;
        while(temp!=NULL){
            if(mm.find(temp)!=mm.end()){
                return true;
            }
            mm[temp]=1;
            temp=temp->next;
        }

        return false;

}

//Using slow and fast pointers (Optimized approach)
//Time complexity--->O(n)
//Space complexity--->O(1)
bool hasCycle(ListNode *head) {
        ListNode*prev=head;
        ListNode*curr=head;
        while(curr!=NULL && curr->next!=NULL){
            prev=prev->next;
            curr=curr->next->next;
            if(prev==curr) return true;
        }
        return false;
}

int main(){

    return 0;
}
