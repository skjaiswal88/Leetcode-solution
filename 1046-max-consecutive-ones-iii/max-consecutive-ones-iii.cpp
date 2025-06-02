class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int c=0;
        int an=0;

        while(r!=nums.size()){
            if(nums[r]==1){
                r++;
                an=max(an,r-l);
            }
            else{
                if(c<k){
                    r++;
                    c++;
                    an=max(an,r-l);
                }
                else{
                    while(nums[l]==1) l++;
                    l++;
                    r++;
                    an=max(an,r-l);
                }
            }

        }

        return an;
    }
};