class Solution {
public:

    int fun(vector<int>& nums, int k){
        int l=0; int r=0; int c=0; int an=0;

        while(r<nums.size()){
            if(nums[r]%2==1) c++;

            while(c>k){
                if(nums[l]%2==1) {
                    c--;
                }
                l++;
            }
            an=an+r-l+1;
            r++;
        }

        return an; 
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=fun(nums,k);
        int b=fun(nums,k-1);
        
        return a-b;
    }
};