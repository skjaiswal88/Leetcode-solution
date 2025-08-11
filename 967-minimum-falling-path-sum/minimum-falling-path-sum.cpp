class Solution {
public:

    int fun(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>& dp){
        if(j < 0 || j >= n) return INT_MAX; 
        if(i == n - 1) return matrix[i][j]; 

        if(dp[i][j] != 100000) return dp[i][j];  

        int a = fun(matrix,i+1,j-1,n,dp);
        int b = fun(matrix,i+1,j,n,dp);
        int c = fun(matrix,i+1,j+1,n,dp);


        return dp[i][j]=matrix[i][j] + min(a, min(b, c));

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int an=INT_MAX;

        vector<vector<int>> dp(n,vector<int>(n,100000));

        for(int i=0;i<n;i++){
            an=min(an,fun(matrix,0,i,n,dp));
        }

        return an;
    }
};