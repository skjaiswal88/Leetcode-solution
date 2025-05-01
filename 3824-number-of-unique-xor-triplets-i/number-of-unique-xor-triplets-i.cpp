class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1){return 1;}
        else if(n==2){return 2;}
        else{
            int d=int(log2(n)+1);
            return pow(2,d);
        }
        
    }
};