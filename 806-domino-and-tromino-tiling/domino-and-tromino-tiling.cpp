class Solution {
public:
   const int MOD = 1e9 + 7;

int numTilings(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<long long> dp(n + 1, 0);
    vector<long long> sum_dp(n + 1, 0);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    sum_dp[0] = dp[0];
    sum_dp[1] = dp[0] + dp[1];
    sum_dp[2] = sum_dp[1] + dp[2];

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 2 * sum_dp[i - 3]) % MOD;
        sum_dp[i] = (sum_dp[i - 1] + dp[i]) % MOD;
    }

    return dp[n];
}



};




