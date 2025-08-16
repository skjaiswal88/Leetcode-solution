class Solution {
public:

    int fun(vector<vector<vector<int>>>& dp,vector<vector<int>>& grid,int n,int m,int i,int x,int y){
        if(x<0 || x>=m || y<0 || y>=m){
            return -1e9;
        }
        if(i==n-1){
            if(x==y){
                return grid[i][x];
            }
            else{
                return grid[i][x] + grid[i][y];
            }
        }

        if(dp[i][x][y]!=-1) return dp[i][x][y];

        int ma=INT_MIN;
        int an;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                if(x==y){
                    an= grid[i][x] + fun(dp,grid,n,m,i+1,x+di,y+dj);
                }
                else{
                    an= grid[i][x] + grid[i][y] + fun(dp,grid,n,m,i+1,x+di,y+dj);
                }
                ma=max(ma,an);
            }
        }
        return dp[i][x][y]=ma;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1))) ; 

        return fun(dp,grid,n,m,0,0,m-1);
    }
};