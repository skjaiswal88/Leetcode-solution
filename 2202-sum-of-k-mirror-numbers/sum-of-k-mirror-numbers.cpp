class Solution {
public:
    // Helper: Check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    // Helper: Convert integer to base-k string
    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += to_string(num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        // Start generating palindromes of increasing length
        for (int len = 1; count < n; len++) {
            int halfLen = (len + 1) / 2;

            // Lower and upper bounds for the first half of the palindrome
            int start = pow(10, halfLen - 1);
            int end = pow(10, halfLen);

            for (int i = start; i < end && count < n; ++i) {
                string half = to_string(i);
                string full = half;

                // Mirror the half to create full palindrome
                if (len % 2 == 1) half.pop_back(); // Avoid duplicating the middle digit
                reverse(half.begin(), half.end());
                full += half;

                long long num = stoll(full);
                if (isPalindrome(toBaseK(num, k))) {
                    sum += num;
                    count++;
                }
            }
        }

        return sum;
    }
};
