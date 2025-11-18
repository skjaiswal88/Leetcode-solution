class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        int i=0;
        int j=1;
        int an=0;

        sort(pairs.begin(),pairs.end(), [](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        });

        while(j<n){
            if(pairs[i][1]>=pairs[j][0]){
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