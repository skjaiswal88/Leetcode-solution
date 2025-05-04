class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1) return rotations;
        return check(bottoms[0], tops, bottoms);
    }
    
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int topRot = 0, bottomRot = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1; // target is not present in either top or bottom
            } else if (tops[i] != target) {
                topRot++;
            } else if (bottoms[i] != target) {
                bottomRot++;
            }
        }
        return min(topRot, bottomRot);
    }
};
