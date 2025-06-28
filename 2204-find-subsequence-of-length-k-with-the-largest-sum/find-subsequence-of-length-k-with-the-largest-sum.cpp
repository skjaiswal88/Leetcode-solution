class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<pair<int, int>> indexed;
        for (int i = 0; i < nums.size(); ++i) {
            indexed.emplace_back(nums[i], i);
        }


        sort(indexed.begin(), indexed.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });


        vector<pair<int, int>> topK(indexed.begin(), indexed.begin() + k);

        sort(topK.begin(), topK.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        // Extract the values
        vector<int> result;
        for (auto& [val, idx] : topK) {
            result.push_back(val);
        }

        return result;
    }
};
