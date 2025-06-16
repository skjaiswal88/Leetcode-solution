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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        bool fl=true;

        if(root==nullptr) return v;
        q.push(root);
        int s=1;

        while(!q.empty()){
            int n=s;
            vector<int> t(s);
            while(s){
                TreeNode* f=q.front();
                q.pop();

                if(f->left!=nullptr) q.push(f->left);
                if(f->right!=nullptr) q.push(f->right);

                if(fl){
                    t[n-s]=f->val;
                }
                else{
                    t[s-1]=f->val;
                }
                s--;
            }
            v.push_back(t);
            fl=!fl;
            s=q.size();
        }
        return v;
    }
};