class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> v(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]==0){
                    v[i][j]=0;
                    q.push({i,j});

                }
                }
                }

                    vector<pair<int,int>> o={{1,0},{0,1},{-1,0},{0,-1}};
                    
                    while(!q.empty()){
                        auto [i,j]=q.front();  q.pop();
                        for(auto [x,y]:o){
                            int u=i+x;
                            int z=j+y;

                            if(u>=0 && z>=0 && u<n && z<m && v[u][z] > v[i][j] + 1){
                                v[u][z]=v[i][j] + 1;
                                q.push({u,z});
                            }
                        }
                    }
                
            

        return v;
    }
};