class Solution {
public:
    const int MOD = 1e9 + 7;

    int colorTheGrid(int m, int n) {
        vector<vector<int>> validStates;
        vector<int> curr;
        generateStates(m, 0, curr, validStates);
        
        int stateCount = validStates.size();
        vector<vector<int>> transitions(stateCount);

        // Precompute valid transitions between states
        for (int i = 0; i < stateCount; ++i) {
            for (int j = 0; j < stateCount; ++j) {
                if (isValidTransition(validStates[i], validStates[j])) {
                    transitions[i].push_back(j);
                }
            }
        }

        vector<int> dp(stateCount, 1); // Base case: 1 way for each valid column state

        for (int col = 1; col < n; ++col) {
            vector<int> newDp(stateCount, 0);
            for (int i = 0; i < stateCount; ++i) {
                for (int prev : transitions[i]) {
                    newDp[i] = (newDp[i] + dp[prev]) % MOD;
                }
            }
            dp = newDp;
        }

        int result = 0;
        for (int val : dp) {
            result = (result + val) % MOD;
        }

        return result;
    }

private:
    void generateStates(int m, int row, vector<int>& curr, vector<vector<int>>& states) {
        if (row == m) {
            states.push_back(curr);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (row == 0 || curr[row - 1] != color) {
                curr.push_back(color);
                generateStates(m, row + 1, curr, states);
                curr.pop_back();
            }
        }
    }

    bool isValidTransition(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }
};
