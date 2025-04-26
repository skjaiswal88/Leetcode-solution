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

void pre(TreeNode* root,vector<int> &an){
    if(root==nullptr) {return ;}


    pre(root->left,an);
    pre(root->right,an);
    an.push_back(root->val);
    
}



class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> an;
        
        pre(root,an);
        return an;
        
    }
};