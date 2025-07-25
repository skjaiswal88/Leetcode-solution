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
    bool fun(TreeNode* r1, TreeNode* r2 ){
        if(r1==nullptr && r2==nullptr) return true;
        if(r1==nullptr || r2==nullptr) return false;

        return ((r1->val==r2->val) && fun(r1->left,r2->left) && fun(r1->right,r2->right));

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
};