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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==nullptr) return v;
        queue<TreeNode*> q;
        int va;
        
        q.push(root);
        int s=1;

        while(!q.empty()){
            while(s){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);

                va=temp->val;
                s--;
            }
            v.push_back(va);
            s=q.size();
        }

        return v;
    
    }
};