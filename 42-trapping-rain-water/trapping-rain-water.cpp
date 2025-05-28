class Solution {
public:
    int trap(vector<int>& height) {
        int l=0; int r=height.size()-1;
        int lm=0; int rm=0;
        int an=0;

        while(l<r){
            if(height[l]<height[r]){
                if(lm>height[l]){
                    an=an+(lm-height[l]);
                }
                else{
                    lm=height[l];
                }
                l++;
            }
            else{
                if(rm>height[r]){
                    an=an+(rm-height[r]);
                }
                else{
                    rm=height[r];
                }
                r--;
            }
        }

        return an;
    }
};