class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full;
        set<int> dryDays;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                int lake = rains[i];
                ans[i] = -1;
                if (full.count(lake)) {
                    int lastFillDay = full[lake];
                    auto it = dryDays.upper_bound(lastFillDay);
                    if (it == dryDays.end()) return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                full[lake] = i;
            }
        }
        return ans;
    }
};
