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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= new TreeNode(preorder[0]);
        TreeNode* temp=root;

        for(int i=1;i<preorder.size();i++){
            temp=root;
            TreeNode* node=new TreeNode(preorder[i]);
            while(temp!=nullptr){
                if(temp->val>node->val){
                    if(temp->left==nullptr){
                        temp->left=node;
                        break;
                    }
                    temp=temp->left;
                }
                else{
                    if(temp->right==nullptr){
                        temp->right=node;
                        break;
                    }
                    temp=temp->right;
                }
            }
        }

        return root;
    }
};