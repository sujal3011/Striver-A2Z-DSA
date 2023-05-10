#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Brute force (extra space,creating a new list)
//Time complexity--->O(n1+n2)
//Space complexity--->O(n1+n2)

 ListNode*func(vector<int>vec){
        ListNode*head=new ListNode();
        ListNode*temp=head;
        head->val=vec[0];
        head->next=NULL;
        for(int i=1;i<vec.size();i++){
            ListNode*nd=new ListNode();
            nd->val=vec[i];
            nd->next=NULL;
            temp->next=nd;
            temp=temp->next;
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode*p1=list1;
        ListNode*p2=list2;
        vector<int>vec;
        while(p1!=NULL && p2!=NULL){
            if(p1->val<p2->val){
                vec.push_back(p1->val);
                p1=p1->next;
            }
            else{
                vec.push_back(p2->val);
                p2=p2->next;
            }
            
        }
        while(p1!=NULL){
            vec.push_back(p1->val);
            p1=p1->next;
        }
        while(p2!=NULL){
            vec.push_back(p2->val);
            p2=p2->next;
        }
        ListNode*head=func(vec);
        return head;
}

//Optimized appraoch (Merging in place)
//Time complexity--->O(n1+n2)
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



int main(){

    return 0;
}
