class Solution {
public:

    int fun(vector<int>& nums, int mid) {
        int c=1;
        int la=0;
        for(int v:nums){
            if(la+v>mid){
                c++;
                la=v;
            }
            else{
                la=la+v;
            }
        }

        return c;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int mid;

        while(low<=high){
            mid=(low+high)/2;

            if(fun(nums,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};