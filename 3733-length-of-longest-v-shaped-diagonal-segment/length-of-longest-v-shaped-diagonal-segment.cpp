class Solution {
public:
    vector<vector<int>> DIRS = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(1 << 4, 0)));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                for (int k = 0; k < 4; k++) {
                    ans = max(ans, dfs(i, j, k, 1, 2, grid, memo));
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j, int k, int canTurn, int target,
            vector<vector<int>>& grid,
            vector<vector<vector<int>>>& memo) {
        i += DIRS[k][0];
        j += DIRS[k][1];
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != target) {
            return 1;  // current cell counts, can't go further
        }
        int mask = (k << 2) | (canTurn << 1) | (target % 2);
        if (memo[i][j][mask] > 0) return memo[i][j][mask];

        int res = dfs(i, j, k, canTurn, 2 - target, grid, memo);
        if (canTurn == 1) {
            int nk = (k + 1) % 4; // clockwise
            res = max(res, dfs(i, j, nk, 0, 2 - target, grid, memo));
        }
        return memo[i][j][mask] = res + 1;
    }
};
