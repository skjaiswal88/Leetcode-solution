class Solution {
public:
    int fun(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return 100000;

        if(dp[n][m]!=0) return dp[n][m];

        int a=fun(n-1,m,grid,dp)+grid[n][m];
        int b=fun(n,m-1,grid,dp)+grid[n][m];

        return dp[n][m]=min(a,b);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        return fun(n-1,m-1,grid,dp);
    }
};