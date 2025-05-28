class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2,
                               int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        // build adjacency
        for (auto &e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        // helper: BFS from src up to distance D, return count reached
        auto ball = [&](auto &g, int src, int D) {
            if (D < 0) return 0;        // no nodes reachable
            int N = g.size();
            vector<int> dist(N, -1);
            queue<int> q;
            dist[src] = 0;
            q.push(src);
            int cnt = 1;                // src itself
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (dist[u] == D) continue;
                for (int v : g[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        if (dist[v] <= D) {
                            ++cnt;
                            q.push(v);
                        }
                    }
                }
            }
            return cnt;
        };

        // Precompute in tree2 for D2 = k-1
        vector<int> best2(m);
        for (int j = 0; j < m; ++j) {
            best2[j] = ball(g2, j, k - 1);
        }
        // Compute the global maximum over j
        int max2 = 0;
        for (int x : best2) max2 = max(max2, x);

        // Precompute in tree1 for D1 = k
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int c1 = ball(g1, i, k);
            ans[i] = c1 + max2;
        }
        return ans;
    }
};
