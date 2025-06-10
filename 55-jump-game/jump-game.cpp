class Solution {
public:
    bool canJump(vector<int>& nums) {
        int an=0;

        for(int i=0;i<nums.size();i++){
            if(an<i) return false;
            an=max(an,nums[i]+i);
        }
        return true;
    }
};