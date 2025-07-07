class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<pair<int, int>> o = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                grid[0][j]=2;
                q.push({0,j});
            }
            if(grid[n-1][j]==1){
                grid[n-1][j]=2;
                q.push({n-1,j});
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                grid[i][0]=2;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                grid[i][m-1]=2;
                q.push({i,m-1});
            }
        }

        while(!q.empty()){
            auto [i,j]=q.front(); 
            q.pop();
            

            for(auto[x,y]: o){
                int nx=x+i;
                int ny=y+j;

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
        }

        int an=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    an++;
                }
            }
        }

        return an;
    }
};