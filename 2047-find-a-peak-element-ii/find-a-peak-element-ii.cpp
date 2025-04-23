class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0) return {};
        int m = mat[0].size();
        if(m == 0) return {};

        // Handle 1x1 matrix.
        if(n == 1 && m == 1) {
            return {0, 0};
        }
        
        // Handle 1-row matrix.
        if(n == 1) {
            for (int j = 0; j < m; j++) {
                bool leftOk = (j == 0 || mat[0][j] > mat[0][j-1]);
                bool rightOk = (j == m-1 || mat[0][j] > mat[0][j+1]);
                if(leftOk && rightOk)
                    return {0, j};
            }
            return {0, 0}; // fallback
        }
        
        // Handle 1-column matrix.
        if(m == 1) {
            for (int i = 0; i < n; i++) {
                bool upOk = (i == 0 || mat[i][0] > mat[i-1][0]);
                bool downOk = (i == n-1 || mat[i][0] > mat[i+1][0]);
                if(upOk && downOk)
                    return {i, 0};
            }
            return {0, 0}; // fallback
        }

        vector<int> v;
        
        // Check four corners.
        if(mat[0][0] > mat[0][1] && mat[0][0] > mat[1][0]) {
            v.push_back(0);  
            v.push_back(0);
            return v;
        }
        if(mat[0][m-1] > mat[0][m-2] && mat[0][m-1] > mat[1][m-1]) {
            v.push_back(0);  
            v.push_back(m-1);
            return v;
        }
        if(mat[n-1][m-1] > mat[n-1][m-2] && mat[n-1][m-1] > mat[n-2][m-1]) {
            v.push_back(n-1);  
            v.push_back(m-1);
            return v;
        }
        if(mat[n-1][0] > mat[n-1][1] && mat[n-1][0] > mat[n-2][0]) {
            v.push_back(n-1);  // Fixed: use n-1 instead of n-2.
            v.push_back(0);
            return v;
        }
        
        // Check top and bottom borders (excluding corners).
        for(int j = 1; j < m-1; j++){
            if(mat[0][j] > mat[0][j-1] && mat[0][j] > mat[0][j+1] 
            && mat[0][j] > mat[1][j]){
                v.push_back(0);  
                v.push_back(j);
                return v;
            }
            if(mat[n-1][j] > mat[n-1][j-1] && mat[n-1][j] > mat[n-1][j+1] 
            && mat[n-1][j] > mat[n-2][j]){
                v.push_back(n-1);  
                v.push_back(j);
                return v;
            }
        }
        
        // Check left and right borders (excluding corners).
        for(int i = 1; i < n-1; i++){
            if(mat[i][0] > mat[i][1] && mat[i][0] > mat[i-1][0] 
            && mat[i][0] > mat[i+1][0]){
                v.push_back(i);  
                v.push_back(0);
                return v;
            }
            if(mat[i][m-1] > mat[i][m-2] && mat[i][m-1] > mat[i-1][m-1] 
            && mat[i][m-1] > mat[i+1][m-1]){
                v.push_back(i);  
                v.push_back(m-1);
                return v;
            }
        }
        
        // Check interior cells: for each row, apply binary search on columns 1..m-2.
        for(int i = 1; i < n-1; i++){
            int low = 1, high = m - 2, mid;
            while(low <= high) {
                mid = (low + high) / 2;
                if(mat[i][mid] > mat[i][mid-1] && mat[i][mid] > mat[i][mid+1] &&
                   mat[i][mid] > mat[i-1][mid] && mat[i][mid] > mat[i+1][mid]) {
                    v.push_back(i);  
                    v.push_back(mid);
                    return v;
                }
                // Adjust horizontal search based on left neighbor comparison.
                if(mat[i][mid] > mat[i][mid-1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        // If no peak is found (should not happen per problem guarantee), return empty vector.
        return v;
    }
};
