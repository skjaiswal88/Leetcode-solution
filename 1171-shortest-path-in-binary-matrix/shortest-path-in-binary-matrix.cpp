class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> st;
        queue<pair<int,int>> q;
        int c=0;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        q.push({0,0});
        st.insert({0,0});

        vector<pair<int,int>> di={
            {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}
        };

        while(!q.empty()){
            int sz = q.size();
            c++; 

            for (int k = 0; k < sz; ++k) {
            auto [x,y]=q.front(); q.pop();
            if(x==n-1 && y==n-1) return c;

            for(auto[i,j]:di){
                int nx=x+i;
                int ny=y+j;

                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && !st.count({nx,ny})){
                    q.push({nx,ny});
                    st.insert({nx,ny});
                }
            }

        }
        }

        return -1;
        


    }
};