#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;

        v.push_back({1});  

        for (int j = 0; j < numRows - 1; j++) {
            vector<int> q;
            q.push_back(1);  
            int n = j + 1;
            long long an = 1;

            for (int i = 0; i < j + 1; i++) {
                an = an * (n - i);
                an = an / (i + 1);
                q.push_back(an);
            }

            v.push_back(q);
        }

        return v;
    }
};