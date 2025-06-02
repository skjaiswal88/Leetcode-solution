class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        vector<int> candies(n, 1);
        
        // Left-to-right pass: ensure each child with a higher rating than the left neighbor gets more candies
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Right-to-left pass: ensure each child with a higher rating than the right neighbor gets more candies
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Sum up the total candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }
        return total;
    }
};
