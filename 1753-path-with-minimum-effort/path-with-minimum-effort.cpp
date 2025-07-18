class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        v[0][0]=0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0,0,0});

        vector<pair<int, int>> di = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        while(!pq.empty()){
            auto[ef,x,y]=pq.top(); pq.pop();
            if(x==n-1 && y==m-1) return ef;

            for(auto[i,j]:di){
                int nx=i+x;
                int ny=j+y;

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int d=abs(heights[x][y]-heights[nx][ny]);
                    int me=max(d,ef);
                    if(me<v[nx][ny]){
                        v[nx][ny]=me;
                        pq.push({me,nx,ny});
                    }
                }

            }
        }
            return v[n-1][m-1];
    }
};