class Solution {
public:

    int fun(vector<int>& w, int c){
        int d=1;
        int l=0;
        for(int v:w){
            if(l+v>c){d++; l=v;}
            else{
                l=l+v;
            }
        }
            return d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int mid;

        while(low<=high){
            mid=(low+high)/2;

            if(fun(weights,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};