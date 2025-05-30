class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;


        vector<vector<int>> g1(n), g2(m);
        for (auto &e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }


        vector<int> parity1(n, -1);
        queue<int> q;
        parity1[0] = 0;
        q.push(0);
        int E1 = 1, O1 = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g1[u]) {
                if (parity1[v] == -1) {
                    parity1[v] = parity1[u] ^ 1;
                    if (parity1[v] == 0) ++E1; else ++O1;
                    q.push(v);
                }
            }
        }


        vector<int> parity2(m, -1);
        parity2[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g2[u]) {
                if (parity2[v] == -1) {
                    parity2[v] = parity2[u] ^ 1;
                    q.push(v);
                }
            }
        }

        int E2 = 0, O2 = 0;
        for (int j = 0; j < m; ++j) {
            if (parity2[j] == 0) ++E2;
            else ++O2;
        }

        int max2odd = 0;
        for (int j = 0; j < m; ++j) {
            int cnt = (parity2[j]==0 ? O2 : E2);
            max2odd = max(max2odd, cnt);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int count1 = (parity1[i]==0 ? E1 : O1);
            ans[i] = count1 + max2odd;
        }
        return ans;
    }
};
