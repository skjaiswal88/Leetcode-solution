class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        int i=0;
        int j=1;
        int an=0;

        sort(points.begin(),points.end(), [](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        });

        while(j<n){
            if(points[i][1]>=points[j][0]){
                an++;
                j++;
                
            }
            else{
                i=j;
                j++;
            }
        }


        return n-an;
    }
};