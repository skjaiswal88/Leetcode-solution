class Solution {
public:
    int climbStairs(int n) {
        int p1=0;
        int p2=1;
        int an=0;

        for(int i=0;i<n;i++){
            an=p1+p2;
            p1=p2;
            p2=an;
        }

        return an;
    }
};