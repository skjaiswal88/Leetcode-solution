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

    int fun(TreeNode* root, int & an){
        if(root==nullptr) return 0;
        int left=max(0,fun(root->left,an));
        int right=max(0,fun(root->right,an));
        an=max(an,root->val + max(0,left) + max(0,right));
        return(root->val+max(0,max(left,right)));
    }

    int maxPathSum(TreeNode* root) {
        int an=INT_MIN;
        fun(root,an);
        return an;
    }
};