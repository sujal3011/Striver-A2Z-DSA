#include<bits/stdc++.h>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Brute force approach
//For every node of list 1 traversing through list 2 and checking whether that node is present in list 2 or not
//Time complexity--->O(n*m)
//Space complexity--->O(1)

 

//Better approach
//Hashing
//Time complexity--->O(n+m)
//Space complexity--->O(1)



//Optimal approach-1
//Time complexity--->O(2*m),where m is the length of the longer linked list
//Space complexity--->O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*d1=headA;
        ListNode*d2=headB;
        int n=0,m=0;

        //finding the length of the lists
        while(d1!=NULL || d2!=NULL){
            if(d1!=NULL){
                n++;
                d1=d1->next;
            }
            if(d2!=NULL){
                m++;
                d2=d2->next;
            }
        }
        d1=headA,d2=headB;

        //traversing through the longer list through a distance equal to the difference in the lengths of the two lists
        if(n>=m){
            for(int i=0;i<n-m;i++){
                d1=d1->next;
            }
        }
        else{
            for(int i=0;i<m-n;i++){
                d2=d2->next;
            }
        }
        //moving the two pointers simultaneously until they intersect
        while(d1!=d2){
            d1=d1->next;
            d2=d2->next;
        }
        return d1;

}


//Optimal approach-2
//Time complexity--->O(2*m),where m is the length of the longer linked list
//Space complexity--->O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*d1=headA,*d2=headB;
        while(d1!=d2){
            d1= d1==NULL? headB : d1->next;
            d2= d2==NULL? headA : d2->next;
        }
        return d1;

}