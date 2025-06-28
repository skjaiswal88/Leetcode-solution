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

    TreeNode* fun(TreeNode* temp){
        while(temp->left){
            temp=temp->left;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;

            if(key<root->val){
                root->left = deleteNode(root->left,key);
            }
            else if(key>root->val){
                root->right = deleteNode(root->right,key);
            }
            else{
                if(root->left==nullptr && root->right==nullptr){
                    delete root;
                    return nullptr;
                }
                else if(root->left==nullptr){
                    TreeNode* n=root->right;
                    delete root;
                    return n;
                }
                else if(root->right==nullptr){
                    TreeNode* n=root->left;
                    delete root;
                    return n;
                }
                else{
                    TreeNode* n=fun(root->right);
                    root->val=n->val;
                    root->right=deleteNode(root->right,n->val);
                }

            }

        return root;
        
    }
};