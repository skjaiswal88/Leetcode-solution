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
    int widthOfBinaryTree(TreeNode* root) {
        int an=0;
        if(root==nullptr) return an;
        queue<pair<unsigned long long,TreeNode*>> q;

        q.push({1,root});
        unsigned long long s=1;
        unsigned long long a=0;
        unsigned long long b=0;

        while(!q.empty()){
            a=q.front().first;
            while(s){
                pair<unsigned long long,TreeNode*> p=q.front();
                q.pop();

                b=p.first;

                if(p.second->left!=nullptr) q.push({p.first*2,p.second->left});
                if(p.second->right!=nullptr) q.push({p.first*2+1,p.second->right});
                s--;
            }
            an = max(an, static_cast<int>(b - a + 1));
            s=q.size();
        }

        return an;
    }
};