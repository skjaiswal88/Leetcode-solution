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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==nullptr) return v;

        int s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            s=q.size();
            vector<int> t;
            while(s){
                if(q.front()->left!=nullptr) q.push(q.front()->left);
                if(q.front()->right!=nullptr) q.push(q.front()->right);
                t.push_back(q.front()->val);
                q.pop();
                s--;
            }
            v.push_back(t);
        }

        return v;
    }
};