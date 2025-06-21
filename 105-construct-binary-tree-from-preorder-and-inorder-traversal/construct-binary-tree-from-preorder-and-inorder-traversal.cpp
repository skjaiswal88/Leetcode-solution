class Solution {
public:
    TreeNode* fun(vector<int>& inorder, int is, int ie,
                  vector<int>& preorder, int ps, int pe,
                  unordered_map<int, int>& mp) {
        if (ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(preorder[ps]);

        int d = mp[preorder[ps]];
        int leftSize = d - is;

        root->left = fun(inorder, is, d - 1, preorder, ps + 1, ps + leftSize, mp);
        root->right = fun(inorder, d + 1, ie, preorder, ps + leftSize + 1, pe, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return fun(inorder, 0, inorder.size() - 1,
                   preorder, 0, preorder.size() - 1, mp);
    }
};
