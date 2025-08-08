#include <unordered_map>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0; 
        
        int N = (n + 24) / 25;

        vector<vector<double>> dp(N + 1, vector<double>(N + 1, -1.0));

        function<double(int,int)> serve = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5; 
            if (a <= 0) return 1.0;          
            if (b <= 0) return 0.0;         

            if (dp[a][b] >= 0) return dp[a][b];

            dp[a][b] = 0.25 * (
                serve(a - 4, b) +
                serve(a - 3, b - 1) +
                serve(a - 2, b - 2) +
                serve(a - 1, b - 3)
            );
            return dp[a][b];
        };

        return serve(N, N);
    }
};
