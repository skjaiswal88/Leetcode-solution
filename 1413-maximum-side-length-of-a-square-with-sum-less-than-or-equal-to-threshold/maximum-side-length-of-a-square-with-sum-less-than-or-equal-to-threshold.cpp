class Solution {
public:
    int getSum(int x1, int y1, int x2, int y2, int mid,
               vector<vector<int>>& prefix) {
        int sum = prefix[x2][y2];
        if (x1 > 0) {
            sum -= prefix[x1 - 1][y2];
        }
        if (y1 > 0) {
            sum -= prefix[x2][y1 - 1];
        }
        if (x1 > 0 && y1 > 0) {
            sum += prefix[x1 - 1][y1 - 1];
        }
        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));
        prefix[0][0] = mat[0][0];

        for (int j = 1; j < m; j++) {
            prefix[0][j] = prefix[0][j - 1] + mat[0][j];
        }
        for (int i = 1; i < n; i++) {
            prefix[i][0] = prefix[i - 1][0] + mat[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                prefix[i][j] = mat[i][j] + prefix[i - 1][j] + prefix[i][j - 1] -
                               prefix[i - 1][j - 1];
            }
        }

        int low = 1;
        int high = min(n, m);
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool found = false;

            for (int i = 0; i + mid - 1 < n; i++) {
                for (int j = 0; j + mid - 1 < m; j++) {
                    int x2 = i + mid - 1;
                    int y2 = j + mid - 1;

                    if (getSum(i, j, x2, y2, mid, prefix) <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};