class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int ans = 0;
        int left = 0, total = 0;

        for (int right = 0; right < n; ++right) {
            total += fruits[right][1];

            while (left <= right) {
                int lPos = fruits[left][0], rPos = fruits[right][0];

                int steps1 = abs(startPos - lPos) + (rPos - lPos);

                int steps2 = abs(startPos - rPos) + (rPos - lPos);

                int minSteps = min(steps1, steps2);

                if (minSteps <= k) break;

                total -= fruits[left][1];
                ++left;
            }

            ans = max(ans, total);
        }

        return ans;
    }
};
