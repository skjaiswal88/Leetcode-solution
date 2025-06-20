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
    int fun(TreeNode* root){
        int a=0;
        while(root){
            root=root->left;
            a++;
        }
        return a;
    }

    int fu(TreeNode* root){
        int a=0;
        while(root){
            root=root->right;
            a++;
        }
        return a;
    }


    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int le=fun(root);
        int ri=fu(root);

        if(le==ri) return (1<<le)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};