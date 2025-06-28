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
class Solution {
public:

    int result=-1;
    int count=0;

    void fun(TreeNode* root, int k){
        if(root->left!=nullptr){
            fun(root->left,k);
        }
        count++;
        if(count==k){
            result=root->val;
        }

        if(root->right!=nullptr){
            fun(root->right,k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        fun(root,k);
        return result;
    }
};