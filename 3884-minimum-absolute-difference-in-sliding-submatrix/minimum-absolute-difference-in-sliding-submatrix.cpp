class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> res(rows - k + 1, vector<int>(cols - k + 1));

        auto computeDiff = [&](multiset<int>& window) {
            if (window.size() < 2) 
                return 0;

            int minDiff = INT_MAX;
            auto prev = window.begin();
            auto it = next(prev);

            while (it != window.end()) {
                int d = *it - *prev;
                if (d > 0) minDiff = min(minDiff, d);
                prev = it;
                it++;
            }

            return minDiff == INT_MAX ? 0 : minDiff;
        };

        for (int r = 0; r <= rows - k; r++) {
            multiset<int> window;

            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++)
                    window.insert(grid[r + i][j]);

            res[r][0] = computeDiff(window);

            for (int c = 1; c <= cols - k; c++) {
                for (int i = 0; i < k; i++)
                    window.erase(window.find(grid[r + i][c - 1]));

                for (int i = 0; i < k; i++)
                    window.insert(grid[r + i][c + k - 1]);

                res[r][c] = computeDiff(window);
            }
        }

        return res;
    }
};