class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; 
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);
        
        
        vector<int> ends;
        for (auto& e : events) ends.push_back(e[1]);

        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int s = events[i - 1][0];
            int e = events[i - 1][1];
            int v = events[i - 1][2];
            
            
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (ends[mid - 1] < s) lo = mid;
                else hi = mid - 1;
            }
            int prev = (lo > 0 && ends[lo - 1] < s) ? lo : 0;

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + v);
            }
        }
        return dp[n][k];
    }
};
