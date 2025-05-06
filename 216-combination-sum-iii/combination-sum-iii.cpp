class Solution {
public:

    void fun(int k,int n, vector<vector<int>> &v,vector<int> p,int st){
        if(p.size()==k && n==0){
            v.push_back(p);
            return;
        }

        for(int i=st;i<=9;i++){
            if(i<=n){
                p.push_back(i);
                fun(k,n-i,v,p,i+1);
                p.pop_back();
            }
            else{break;}
        }


    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        if(k>n) {return v;}

        vector<int> p;

        fun(k,n,v,p,1);
        
        return v;
    }
};