class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 && j==0) {
                    dp[0][0] = grid[0][0];
                    continue;
                }

                int a=grid[i][j];
                int b=grid[i][j];

                if(i>0){
                    a=a+dp[i-1][j];
                }
                else{
                    a=100000;
                }

                if(j>0){
                    b=b+dp[i][j-1];
                }
                else{
                    b=100000;
                }

                dp[i][j]=min(a,b);

            }
        }



        return dp[n-1][m-1];
    }
};