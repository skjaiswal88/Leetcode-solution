class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0; int high=n-1;
        int mid;
        int mi;

        while(low<=high){
            mid=(low+high)/2;
            mi=arr[mid]-mid-1;
            if(mi<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }


        }
        return k+high+1;
    }
};