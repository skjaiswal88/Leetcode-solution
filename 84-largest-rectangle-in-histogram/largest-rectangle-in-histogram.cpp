class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int an=0;
        int c,nse,pse;
        stack<int> s;

        for(int i=0;i<=n;i++){
            int currHeight = (i == n) ? 0 : heights[i];

            while(!s.empty() && currHeight<heights[s.top()]) {
                c=s.top();
                s.pop();
                nse=i;
                pse=s.empty() ? -1 : s.top();

                an=max(an,(nse-pse-1)*heights[c]);
            }
            s.push(i);
        }
        
        return an;
    }
};