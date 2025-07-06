class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val=image[sr][sc];
        if (val == color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});

        int n=image.size(); 
        int m=image[0].size();

        vector<pair<int,int>> v={{-1,0},{1,0},{0,-1},{0,1}};
        set<pair<int,int>> st;

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();

            int io=p.first;
            int jo=p.second;
            image[io][jo]=color;

            for(auto [x,y]:v){
                int i=io+x; 
                int j=jo+y;

                if(i>=0 && j>=0 && i<n && j<m && image[i][j]==val && !st.count({i,j})){
                    image[i][j]=color;
                    st.insert({i,j});
                    q.push({i,j});
                    
                }
            }
        }

        return image;

    }
};