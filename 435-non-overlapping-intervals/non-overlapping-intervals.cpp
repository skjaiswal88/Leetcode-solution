class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int i=0;
        int j=1;
        int an=0;

        sort(intervals.begin(), intervals.end(),
     [](const vector<int>& a, const vector<int>& b) {
         return a[1] < b[1];  
     });


        while(j<n){
            if(intervals[i][1]>intervals[j][0]){
                an++;
                j++;
            }
            else{
                i=j;
                j++;
            }
        }

        return an;

    }
};