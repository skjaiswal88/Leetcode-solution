class Solution {
public:

    int fun(vector<int> v){
        int n=v.size();
        stack<int> s;
        int h,nse,pse;
        int an=0;

        for(int i=0;i<=n;i++){
            int cur=(i==n) ? 0: v[i];

            while(!s.empty() && cur<v[s.top()]){
                h=v[s.top()];
                s.pop();
                nse=i;
                pse= s.empty() ? -1: s.top();

                an=max(an,h*(nse-pse-1));

            }
            s.push(i);
        }

        return an;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int an=0;

        vector<int> v(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') v[j]=0;
                else {v[j]++;}
            }

            an=max(an,fun(v));
        }
        return an;
    }
};