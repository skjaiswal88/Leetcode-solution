class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        set<pair<int, int>> st;

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                st.insert({0, j});
            }
            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                st.insert({n - 1, j});
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                st.insert({i, 0});
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                st.insert({i, m - 1});
            }
        }

        vector<pair<int, int>> o = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto [x, y] : o) {
                int nx = x + i;
                int ny = y + j;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    board[nx][ny] == 'O' && !st.count({nx, ny})) {
                    q.push({nx, ny});
                    st.insert({nx, ny});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (st.count({i, j})) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};