/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        if(root==NULL) return v;
        TreeNode* Root=root;
        TreeNode* p;

        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        int s=1;

        while(!q.empty()){
                TreeNode* node=q.front();
                q.pop();

                if(node->left!=NULL){
                    mp[node->left]=node;
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    mp[node->right]=node;
                    q.push(node->right);
                }
            }

        unordered_set<TreeNode*> st;

        q.push(target);
        st.insert(target);
        s=1;
        while(k){
            while(s){
                TreeNode* node=q.front();
                q.pop();

                if(node->left!=NULL && !st.count(node->left)){
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right!=NULL && !st.count(node->right)){
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(mp.find(node)!=mp.end() && !st.count(mp[node])){
                    q.push(mp[node]);
                    st.insert(mp[node]);
                }
                s--;     
            }
            s=q.size(); 
            k--;
        }

        while(!q.empty()){
            v.push_back(q.front()->val);
            q.pop();
        }

        return v;
    }
};