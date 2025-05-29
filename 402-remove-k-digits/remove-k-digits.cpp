class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for (char c : num) {
            while (!s.empty() && k > 0 && s.top() > c) {
                s.pop();
                k--;
            }
            s.push(c);
        }

        // If k > 0, remove remaining digits from end
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        // Build result from stack
        string result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        result = result.substr(i);

        // Handle edge case
        return result.empty() ? "0" : result;
    }
};
