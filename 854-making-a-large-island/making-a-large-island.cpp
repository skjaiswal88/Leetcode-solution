class Disjoint {
    vector<int> pa, s;
public:
    Disjoint(int n) {
        pa.resize(n);
        s.resize(n, 1);
        for (int i = 0; i < n; i++) pa[i] = i;
    }

    int par(int a) {
        if (pa[a] == a) return a;
        return pa[a] = par(pa[a]);
    }

    int si(int a){
    return s[par(a)];
}


    void uni(int a, int b) {
        int ua = par(a);
        int ub = par(b);
        if (ua == ub) return ;

        if (s[ua] > s[ub]) {
            pa[ub] = ua;
            s[ua] += s[ub];
        } else {
            pa[ua] = ub;
            s[ub] += s[ua];
        }
        return ;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint dsu(n*n+1);
        int an=0;

        vector<pair<int,int>> di={
            {0,1},{1,0},{-1,0},{0,-1}
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] == 0) continue;  

                int a=n*i+j;
                for(auto[x,y]:di){
                    int nx=i+x;
                    int ny=j+y;

                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1){
                        int b=n*nx+ny;
                        dsu.uni(a,b);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;
                    int c=0;

                    for(auto[x,y]:di){
                        int nx=i+x;
                        int ny=j+y;

                        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1){
                            int b=n*nx+ny;
                            st.insert(dsu.par(b));
                        }
                    }
                    for(int rep:st){
                        c=c+dsu.si(rep);
                    }

                    an=max(an,c+1);
                }

            }
        }
        if(an==0) return n*n;
        else return an;

    }
};