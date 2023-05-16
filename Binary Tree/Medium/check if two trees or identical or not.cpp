#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Time complexity---O(n)

bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        bool check_left=isSameTree(p->left,q->left);
        bool check_right=isSameTree(p->right,q->right);

        if(check_left && check_right && p->val==q->val) return true;
        return false;
    }

int main(){

    return 0;
}