class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuffix(n);
        minSuffix[n - 1] = s[n - 1];

        // Fill in the smallest character from the right
        for (int i = n - 2; i >= 0; --i) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        string res;
        stack<char> t;

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            // While the top of stack is <= smallest remaining in s
            while (!t.empty() && (i == n - 1 || t.top() <= minSuffix[i + 1])) {
                res += t.top();
                t.pop();
            }
        }

        return res;
    }
};
