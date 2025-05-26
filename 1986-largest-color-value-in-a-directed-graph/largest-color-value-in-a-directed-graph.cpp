class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Build graph and indegree
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        // Kahn's algorithm for topological sort
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.push(i);
        
        // dp[i][c] = max count of color 'a'+c along any path ending at i
        vector<array<int,26>> dp(n);
        for (int i = 0; i < n; ++i)
            dp[i].fill(0);
        
        int visited = 0;
        int answer = 0;
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;
            int colorIdx = colors[u] - 'a';
            // Include this node's color
            dp[u][colorIdx] = dp[u][colorIdx] + 1;
            // Update global answer
            answer = max(answer, dp[u][colorIdx]);
            
            // Propagate to neighbors
            for (int v : adj[u]) {
                for (int c = 0; c < 26; ++c) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // If not all nodes were visited, there is a cycle
        if (visited < n) return -1;
        return answer;
    }
};
