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



    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==nullptr) return v;
        stack<TreeNode*> s;

        s.push(root);

        while(!s.empty()){
            TreeNode* p=s.top();
            s.pop();

            
            if(p->left!=nullptr) s.push(p->left);            
            if(p->right!=nullptr) s.push(p->right);
            v.push_back(p->val);
        }

        reverse(v.begin(),v.end());
        return v;

    }
};