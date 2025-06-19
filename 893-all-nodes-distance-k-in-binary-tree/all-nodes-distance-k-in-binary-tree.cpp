class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        if (root == nullptr) return v;

        // Step 1: Build parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: BFS from target to find nodes at distance K
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int dist = 0;

        while (!q.empty()) {
            if (dist == k) break;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }

        // Step 3: Collect all nodes at distance K
        while (!q.empty()) {
            v.push_back(q.front()->val);
            q.pop();
        }

        return v;
    }
};
