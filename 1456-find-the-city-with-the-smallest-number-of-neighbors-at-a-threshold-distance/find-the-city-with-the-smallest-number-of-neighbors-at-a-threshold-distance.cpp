class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> v(n, vector<int>(n, INT_MAX));

        for (auto e : edges) {
            v[e[0]][e[1]] = e[2];
            v[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (v[i][k] != INT_MAX && v[k][j] != INT_MAX) {
                        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                    }
                }
            }
        }

        pair<int, int> an = {0, INT_MAX};

        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {

                    if (v[i][j] <= distanceThreshold) {
                        c++;
                    }
                }
            }
            if (an.second >= c) {
                an.first = i;
                an.second = c;
            }
        }

        return an.first;
    }
};