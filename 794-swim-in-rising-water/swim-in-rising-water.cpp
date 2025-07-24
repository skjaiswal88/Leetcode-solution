class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        pq.push({grid[0][0], 0, 0});
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        while (!pq.empty()) {
            auto [time, x, y] = pq.top(); pq.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            if (x == n - 1 && y == n - 1) return time;
            
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }
        
        return -1; // Should never reach here
    }
};
