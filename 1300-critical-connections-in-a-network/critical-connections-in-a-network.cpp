class Solution {
public:

    void dfs(int ch, int pa, vector<vector<int>>& adj, vector<int>& ti, vector<int>& l,
             int& c, vector<bool>& vi, vector<vector<int>>& an) {

        vi[ch] = true;
        ti[ch] = l[ch] = c++;
        
        for (int j : adj[ch]) {
            if (j == pa) continue;

            if (!vi[j]) {
                dfs(j, ch, adj, ti, l, c, vi, an);
                l[ch] = min(l[ch], l[j]);

                if (l[j] > ti[ch]) {
                    an.push_back({ch, j});
                }
            } else {
                l[ch] = min(l[ch], ti[j]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        // Build undirected graph
        for (auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);  
        }

        vector<vector<int>> an;
        vector<bool> vi(n, false);
        vector<int> ti(n, -1);
        vector<int> l(n, -1);
        int c = 0;

        dfs(0, -1, adj, ti, l, c, vi, an);
        return an;
    }
};
