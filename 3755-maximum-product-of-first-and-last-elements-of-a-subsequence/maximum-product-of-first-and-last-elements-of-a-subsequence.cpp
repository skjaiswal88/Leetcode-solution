class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        int l=0; int r=n-1;
        long long an=LLONG_MIN;


        vector<int> x(n);
        vector<int> y(n);
        
        x[n - 1] = nums[n - 1];
        y[n - 1] = nums[n - 1];

        for (int i =n - 2; i >= 0; --i) {
            x[i] = max(nums[i], x[i + 1]);
        }

        for (int i =n - 2; i >= 0; --i) {
            y[i] = min(nums[i], y[i + 1]);
        }

        int i=0;
        while (i <= n - m) {
            int j = i + m - 1;  
            long long u =1LL*nums[i] * x[j];
            long long v =1LL * nums[i]*y[j];
            an = max({an,v,u});
            i++;
        }
        

        // while(i<=n-m){
        //     int j=i+m-1;
        //     while(j<n ){
        //         long long r= 1LL * nums[i] * nums[j];
        //         an=max(an, r);
        //         j++;
        //     }
        //     i++;
        // }

        return an;
    }
};