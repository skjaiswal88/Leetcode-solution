class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<int> pre(n, 0);

        for(int i=0;i<m;i++){
            vector<int> tem(n, 0);
            for(int j=0;j<n;j++){
                if (i == 0 && j == 0) {
                tem[j] = 1;
                continue; 
            }

            int l=0;
            int r=0;

            if(i>0) {
                l=pre[j];
            }
            if(j>0) {
                r=tem[j-1];
            }

            tem[j]=l+r;
            }
            pre=tem;
        }


        return pre[n-1];
    }
};
