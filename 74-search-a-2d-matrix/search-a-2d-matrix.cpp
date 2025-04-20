class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0; int high=n-1;
        int mid;
        int r=-1;

        while(low<=high){
            mid=(int)((low+high)/2);
            if(matrix[mid][0]<=target && target<=matrix[mid][m-1]){
                r=mid; break;
            }
            if(matrix[mid][m-1]>target){high=mid-1;}
            else{low=mid+1;}
        }

        if(r==-1){return false;}

        low=0; high=m-1;

        while(low<=high){
            mid=(low+high)/2;
            if(matrix[r][mid]==target){return true;}
            if(matrix[r][mid]<target){low=mid+1;}
            else{high=mid-1;}
        }

        return false;

        
    }
};