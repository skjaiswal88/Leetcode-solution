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
    int cnt(TreeNode* root){
        int an=0;
        queue<TreeNode*> q;
        if(root==nullptr) return 0;

        int s=1;
        q.push(root);

        while(!q.empty()){
            while(s){
                TreeNode* f=q.front();
                q.pop();
                s--;
                if(f->left!=nullptr) q.push(f->left);
                if(f->right!=nullptr) q.push(f->right);
            }
            s=q.size();
            an++;
        }
        return an;
    }

    void fun(TreeNode* root, bool & y){
        if(abs( (cnt(root->left)) - (cnt(root->right)) )>1) {
            y=false;
            return ;
        }
        else{
            if(root->left!=nullptr) fun(root->left,y);
            if(root->right!=nullptr) fun(root->right,y);
        }
    }

    bool isBalanced(TreeNode* root) {
        bool y=true;
        if(root==nullptr) return true;

        fun(root,y);


        return y;
    }
};