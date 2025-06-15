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
    int d=0;

    int h(TreeNode* root){
        if(root==nullptr) return 0;

        int l=h(root->left);
        int r=h(root->right);

        d=max(d,l+r);

        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        h(root);

        return d;

    }
};