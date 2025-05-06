class Solution {
public:

    void fun(vector<int> nums,vector<vector<int>> &v,vector<int> p,int n,int i){
        if(i==n){
            v.push_back(p);
            return;
        }

        p.push_back(nums[i]);
        fun(nums,v,p,n,i+1);
        p.pop_back();
        fun(nums,v,p,n,i+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        vector<int> p;

        fun(nums,v,p,n,0);
        return v;
        
    }
};