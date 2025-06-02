class Solution {
public:

    int fun(vector<int>& v, int g){
        if(g<0) return 0;

        int l=0; int r=0; int s=0; int c=0;

        while(r<v.size()){
            s=s+v[r];
            while(s>g){
                s=s-v[l];
                l++;
            }
            c=c+(r-l+1);
            r++;
        }
        return c;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int a=fun(nums,goal);
        int b=fun(nums,goal-1);
        
        return a-b;
    }
};