class Solution {
public:
    int differenceOfSums(int n, int m) {
        // Total sum of 1..n
        long long total = (long long)n * (n + 1) / 2;
        // Number of multiples of m in [1..n]
        long long k = n / m;
        // Sum of those multiples = m * (1 + 2 + ... + k)
        long long sumDiv = m * (k * (k + 1) / 2);
        // Sum of non-divisible = total - sumDiv
        // We need (non-divisible) - (divisible) = total - 2*sumDiv
        long long diff = total - 2 * sumDiv;
        return (int)diff;
    }
};
