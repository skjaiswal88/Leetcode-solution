class Solution {
public:

    void fun(vector<vector<int>> &v, vector<int> p, vector<int>& c, int t, int i){
        if(t==0){
            v.push_back(p);
            return;
        }
        if(i==c.size() || t<0){return; }

        if(c[i]<=t){
            p.push_back(c[i]);
            fun(v,p,c,t-c[i],i);
            p.pop_back();
        }
        fun(v,p,c,t,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> p;

        fun(v,p,candidates,target,0);

        return v;
        
    }
};