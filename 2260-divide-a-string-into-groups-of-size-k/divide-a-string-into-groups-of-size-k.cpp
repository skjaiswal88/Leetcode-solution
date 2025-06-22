class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();

        int remainder = n % k;
        if (remainder != 0) {
            s += string(k - remainder, fill);
        }

        for (int i = 0; i < s.size(); i += k) {
            result.push_back(s.substr(i, k));
        }

        return result;
    }
};
