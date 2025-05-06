class Solution {
public:
    void fun(vector<vector<int>>& res, vector<int>& temp, vector<int>& c, int t, int index) {
        if (t == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = index; i < c.size(); i++) {
            if (i > index && c[i] == c[i - 1]) continue; // skip duplicates
            if (c[i] > t) break; // early stopping

            temp.push_back(c[i]);
            fun(res, temp, c, t - c[i], i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;

        fun(res, temp, candidates, target, 0);

        return res;
    }
};
