class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; // because we start from 1

        while (k > 0) {
            long count = getCount(curr, n);
            if (count <= k) {
                k -= count;
                curr += 1;
            } else {
                k -= 1;
                curr *= 10;
            }
        }

        return curr;
    }

private:
    long getCount(long prefix, long n) {
        long count = 0;
        long first = prefix;
        long last = prefix + 1;
        while (first <= n) {
            count += min(n + 1L, last) - first;
            first *= 10;
            last *= 10;
        }
        return count;
    }
};
