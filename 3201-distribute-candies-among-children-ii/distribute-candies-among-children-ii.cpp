class Solution {
public:
    using i128 = __int128_t;
    using u128 = __uint128_t;

    // Compute C(x+2, 2) = (x+2)*(x+1)/2, but return 0 if x < 0
    static u128 choose2(i128 x) {
        if (x < 0) return 0;
        u128 xx = (u128)x;
        // (x+2)*(x+1)/2
        return ( (xx + 2) * (xx + 1) ) / 2;
    }

    unsigned long long distributeCandies(unsigned long long nULL,
                                          unsigned long long limitULL) {
        // Upcast to signed 128 for subtraction
        i128 n = (i128)nULL;
        i128 limit = (i128)limitULL;

        // Total number of nonnegative solutions to x+y+z = n  is C(n+2, 2)
        u128 total = choose2(n);

        // Inclusion-Exclusion over which of {x,y,z} exceed 'limit'
        // Let L = limit + 1.  If a variable > limit, say x' = x - L → sum = n - L.
        i128 L = limit + 1;

        // Subtract cases where exactly one variable > limit
        // There are 3 ways to choose that variable, each contributes C(n - L + 2, 2)
        u128 sub1 = 3 * choose2(n - L);

        // Add back cases where exactly two variables exceed limit:
        // Each is chosen in C(3,2)=3 ways, and sum for those two is L+L=2L → remainder n - 2L
        u128 add2 = 3 * choose2(n - 2*L);

        // Subtract the case where all three exceed limit:
        // sum for three is 3L → remainder n - 3L
        u128 sub3 = choose2(n - 3*L);

        u128 answer128 = total - sub1 + add2 - sub3;
        return (unsigned long long)answer128;
    }
};
