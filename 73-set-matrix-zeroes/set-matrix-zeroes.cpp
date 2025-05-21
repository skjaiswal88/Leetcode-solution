class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        auto l=matrix[0];
        int m=(l).size();

        vector<int> ro(n,0);
        vector<int> co(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    ro[i]=1;
                    co[j]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ro[i]==1 || co[j]==1){
                    matrix[i][j]=0;
                }
            }
        }


    }
};