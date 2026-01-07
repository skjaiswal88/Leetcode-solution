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
    // sum[d] = the sum of the nodes on depth d
    map <int, int> sum;
    void dfs(TreeNode* u, int depth){
        sum[depth] += u -> val;
        if(u -> left != NULL){
            dfs(u -> left, depth + 1);
        }
        if(u -> right != NULL){
            dfs(u -> right, depth + 1);
        }
    }
    int maxLevelSum(TreeNode* root) {
        sum.clear();
        dfs(root, 1);
        int d = 1;
        for(auto [depth, s] : sum){
            if(s > sum[d]){
                d = depth;
            }
        }
        return d;
    }
};