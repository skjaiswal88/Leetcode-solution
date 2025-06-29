class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Precompute powers of 2 up to n
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;

        int left = 0, right = n - 1, result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow2[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};
