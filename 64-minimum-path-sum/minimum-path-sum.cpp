class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> pr (m,100000);


        for(int i=0;i<n;i++){
            vector<int> cu (m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    cu[j]=grid[i][j];
                }
                else{
                    int a, b;

                if(i>0){
                    a=pr[j];
                }
                else{
                    a=INT_MAX;
                }

                if(j>0){
                    b=cu[j-1];
                }
                else{
                    b=INT_MAX;
                }

                cu[j]=grid[i][j]+min(a,b);

            }
            }
            pr=cu;
        }



        return pr[m-1];
    }
};