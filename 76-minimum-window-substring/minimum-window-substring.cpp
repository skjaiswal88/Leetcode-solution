class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);  // Use full ASCII range
        vector<int> window(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int have = 0;                // How many characters match need count
        int needCount = t.size();    // Total characters needed (including duplicates)
        int l = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for (int r = 0; r < s.size(); r++) {
            char curr = s[r];
            window[curr]++;

            if (need[curr] > 0 && window[curr] <= need[curr]) {
                have++;
            }

            while (have == needCount) {
                // Update answer
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }

                // Shrink window from left
                char leftChar = s[l];
                window[leftChar]--;

                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        if (minLen == INT_MAX) return "";
        return s.substr(minStart, minLen);
    }
};
