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
    int maxDepth(TreeNode* root) {
        int an=0;
        queue<TreeNode*> q;

        if(root==nullptr) return an;

        q.push(root);
        int s=1;

        while(!q.empty()){

        while(s){
            TreeNode* r=q.front();
            q.pop();
            s--;
            if(r->left!=nullptr) q.push(r->left);
            if(r->right!=nullptr) q.push(r->right);

        }
        an++;
        s=q.size();
        }

        return an;
    }
};