class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        int t=0; int an=0; int r=0;
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) t++;
                if(grid[i][j]==2) {
                    pair<int,int> p;
                    t++; r++;
                    p.first=i;
                    p.second=j;
                    q.push(p);
                }
            }
        }

         if (t-r == 0) return 0;
        
        set<pair<int,int>> st;
        int i; int j;

        while(!q.empty()){
            int s=q.size();

            while(s){
            pair<int,int> tem=q.front(); 
            q.pop();

            if(st.count(tem)) continue;

            st.insert(tem);

            i=tem.first; 
            j=tem.second;

            if(i-1>=0 && grid[i-1][j]==1){
                r++;
                grid[i-1][j]=2;
                pair<int,int> w;
                w.first=i-1;
                w.second=j;
                q.push(w);
            }

            if(j-1>=0 && grid[i][j-1]==1){
                r++;
                grid[i][j-1]=2;
                pair<int,int> w;
                w.first=i;
                w.second=j-1;
                q.push(w);
            }

            if(i+1<n && grid[i+1][j]==1){
                r++;
                grid[i+1][j]=2;
                pair<int,int> w;
                w.first=i+1;
                w.second=j;
                q.push(w);
            }

            if(j+1<m && grid[i][j+1]==1){
                r++;
                grid[i][j+1]=2;
                pair<int,int> w;
                w.first=i;
                w.second=j+1;
                q.push(w);
            }
            s--;
        }
            an++;
            s=q.size();
        }

        if(r==t) return an-1;
        else return -1;
    }
};