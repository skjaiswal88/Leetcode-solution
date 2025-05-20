class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        // Build a DAG: edges only from i → j when j > i
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].size() == words[j].size() &&
                    hammingDistanceOne(words[i], words[j])) {
                    graph[i].push_back(j);
                }
            }
        }

        // dp[u] = length of longest path starting at u
        // nxt[u] = the next node on that path
        vector<int> dp(n, -1), nxt(n, -1);

        function<int(int)> dfs = [&](int u) {
            if (dp[u] != -1) return dp[u];
            int best = 1, bestNext = -1;
            for (int v : graph[u]) {
                int cand = 1 + dfs(v);
                if (cand > best) {
                    best = cand;
                    bestNext = v;
                }
            }
            nxt[u] = bestNext;
            return dp[u] = best;
        };

        // Find the start of the overall longest path
        int start = 0, maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int len = dfs(i);
            if (len > maxLen) {
                maxLen = len;
                start = i;
            }
        }

        // Reconstruct the answer
        vector<string> result;
        while (start != -1) {
            result.push_back(words[start]);
            start = nxt[start];
        }
        return result;
    }

private:
    // Returns true if a and b have same length and hamming distance exactly 1
    bool hammingDistanceOne(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0, n = a.size(); i < n; ++i) {
            if (a[i] != b[i] && ++diff > 1) return false;
        }
        return diff == 1;
    }
};
