class Solution {
public:
    int n;
    vector<vector<int>> dirs{{0,1}, {1,0}, {-1,0}, {0,-1}};

    bool canReach(vector<vector<int>>& grid, int mid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid) return false;
        if (i == n - 1 && j == n - 1) return true;

        visited[i][j] = true;

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (canReach(grid, mid, ni, nj, visited)) return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = grid[0][0], high = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                high = max(high, grid[i][j]);


        while (low < high) {
            int mid = (low + high) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (canReach(grid, mid, 0, 0, visited)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};