class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur;
        for (int x : arr) {
            unordered_set<int> new_cur;
            new_cur.insert(x);
            for (int y : cur) {
                new_cur.insert(x | y);
            }
            cur = new_cur;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};
