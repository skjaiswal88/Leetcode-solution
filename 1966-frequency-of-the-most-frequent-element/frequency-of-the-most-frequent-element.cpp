#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int an=1;
        long long co=0;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=1;

        for(r=1;r<n;r++){
            co=co+(long long)(nums[r]-nums[r-1])*(r-l);

            if(co>k){
                co=co-(nums[r]-nums[l]);
                l++;
            }
            an=max(an,r-l+1);
        }


        return an;
        
    }
};

