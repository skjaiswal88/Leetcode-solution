class Solution {
public:

    int fun(vector<int>& nums, int k){
        if(k<0) return 0;

        unordered_map<int, int> mp;
        int l = 0; int c = 0;

        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;


            if (mp.size() > k) {
                while (mp.size() > k) {
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0) {
                        mp.erase(nums[l]);
                    }
                    l++;
                }
            }

            c=c+(r-l+1);

            
        }

        return c;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int a=fun(nums,k);
        int b=fun(nums,k-1);

        return a-b;
    }
};
