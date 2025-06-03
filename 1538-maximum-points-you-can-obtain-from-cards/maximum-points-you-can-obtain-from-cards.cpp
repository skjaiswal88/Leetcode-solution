class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int t=accumulate(cardPoints.begin(),cardPoints.end(),0);

        if(k==n) return t;

        int ws=n-k;
        int s=0;

        for(int i=0;i<ws;i++){
            s=s+cardPoints[i];
        }
        int an=s;

        for(int j=ws;j<n;j++){
            s=s+cardPoints[j]-cardPoints[j-ws];
            an=min(an,s);
        }
        
        return t-an;
    }
};