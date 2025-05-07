class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        const int INF = INT_MAX;
        
        // dist[x][y] = minimum arrival time at (x,y)
        vector<vector<int>> dist(n, vector<int>(m, INF));
        // Min‑heap of (time, x, y)
        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<>> pq;
        
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto [t, x, y] = pq.top(); 
            pq.pop();
            if (t > dist[x][y]) continue;
            if (x == n - 1 && y == m - 1) return t;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) 
                    continue;
                
                // can only start moving into (nx,ny) at time ≥ moveTime[nx][ny]
                int start = max(t, moveTime[nx][ny]);
                int nt = start + 1;  // +1s to move
                
                if (nt < dist[nx][ny]) {
                    dist[nx][ny] = nt;
                    pq.push({nt, nx, ny});
                }
            }
        }
        
        return -1; // by constraints, you should always reach
    }
};
