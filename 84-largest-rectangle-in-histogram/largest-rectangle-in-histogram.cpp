class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        stack<int> p;
        int an=0;
        int y;

        vector<int> nse(n,n);
        vector<int> pse(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[i]<=heights[s.top()]) s.pop();
            if(!s.empty()) nse[i]=s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++){
            while(!p.empty() && heights[i]<=heights[p.top()]) p.pop();
            if(!p.empty()) pse[i]=p.top();
            p.push(i);
        }

        for(int i=0;i<n;i++){
            y=((nse[i]-i)+(i-pse[i])-1)*heights[i]*1LL;
            an=max(an,y);
        }
        return an;

    }
};