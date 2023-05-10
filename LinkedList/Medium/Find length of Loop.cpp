#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



//Function to find the length of a loop in the linked list.

//Using fast and slow pointers
//Time complexity--->O(n)
//Space complexity--->O(1)
int countNodesinLoop(struct Node *head)
{
    Node*prev=head;
    Node*curr=head;
    bool flag=0;
    while(curr!=NULL && curr->next!=NULL){
        prev=prev->next;
        curr=curr->next->next;
        if(prev==curr){
            flag=1;
            break;
        }
        
    }
    if(!flag) return 0;
    curr=head;
    while(prev!=curr){
        prev=prev->next;
        curr=curr->next;
    }
    int ans=1;
    while(prev->next!=curr){
        ans++;
        prev=prev->next;
    }
    return ans;
}

int main(){

    return 0;
}
