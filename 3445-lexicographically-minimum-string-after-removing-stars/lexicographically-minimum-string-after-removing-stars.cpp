class Solution {
public:
    string clearStars(string s) {
        deque<char> dq;
        map<char, vector<int>> charPos;

        // Build using deque
        for (char ch : s) {
            if (ch == '*') {
                // Find the smallest char
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (!charPos[c].empty()) {
                        // Remove the last inserted position of smallest char
                        int idx = charPos[c].back();
                        charPos[c].pop_back();
                        dq[idx] = '#'; // Mark for deletion
                        break;
                    }
                }
            } else {
                charPos[ch].push_back(dq.size());
                dq.push_back(ch);
            }
        }

        // Build final result
        string res;
        for (char c : dq) {
            if (c != '#') res += c;
        }
        return res;
    }
};
