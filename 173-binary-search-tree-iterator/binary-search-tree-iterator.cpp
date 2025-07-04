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
class BSTIterator {
public:

    vector<int> v;
    int n=0;
    int i=-1;

    void fun(TreeNode* root){
        if(root->left!=nullptr) fun(root->left);
        v.push_back(root->val);
        if(root->right!=nullptr) fun(root->right);
    }


    BSTIterator(TreeNode* root) {
        fun(root);
        n=v.size();

    }
    
    int next() {
        if (hasNext()==true){
            i++;
            return v[i];
        }
        else return -1;
               
    }
    
    bool hasNext() {
        if(i+1<n) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */