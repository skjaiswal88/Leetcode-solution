class Solution {
public:
    // Check if target repeated k times is a subsequence of s
    bool isKRepeatedSubsequence(const string& s, const string& target, int k) {
        int i = 0, count = 0, n = s.size();
        string repeated = "";
        for (int t = 0; t < k; ++t) repeated += target;

        for (char ch : s) {
            if (ch == repeated[i]) {
                i++;
                if (i == repeated.size()) return true;
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        // Count frequency of characters
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Build possible character set
        string candidates = "";
        for (char c = 'z'; c >= 'a'; --c) {
            if (freq[c] >= k) candidates += c;
        }

        string result = "";

        // BFS to generate all combinations in lexicographical descending order
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            for (char c : candidates) {
                string next = curr + c;
                if (isKRepeatedSubsequence(s, next, k)) {
                    if (next.size() > result.size() || (next.size() == result.size() && next > result)) {
                        result = next;
                    }
                    q.push(next); // only push if it's valid to extend
                }
            }
        }

        return result;
    }
};
