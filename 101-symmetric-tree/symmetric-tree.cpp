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

    bool fun(TreeNode* a,TreeNode* b){
        if(a==nullptr && b==nullptr) return true;
        else if(a==nullptr || b==nullptr) return false;
        else {
            if(a->val==b->val) {
                return fun(a->left, b->right) && fun(a->right, b->left);

            }
            else{
                return false;
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr) return true;
        else if(root->left==nullptr || root->right==nullptr) return false;
        else {
            return fun(root->left,root->right);
        }
        
    }
};