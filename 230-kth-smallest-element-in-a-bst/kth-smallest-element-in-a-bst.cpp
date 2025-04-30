/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void ino(TreeNode* root, int k, int &c, int &s){
    if(!root || k<=c) {return;}

    ino(root->left,k,c,s);

    c++;
    if(c==k){
        s=root->val;
    }

    ino(root->right,k,c,s);

} 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int s=INT_MAX;

        ino(root,k,c,s);

        return s;

        
    }
};