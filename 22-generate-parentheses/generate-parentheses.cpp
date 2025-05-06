class Solution {
public:

    void fun(int n,vector<string> &v,int i,string t,int f,int l){
        if(i==2*n && f==l){
            v.push_back(t);
            return;
        }

        // if(t.empty()){
        //     fun(n,v,i+1,t+'(',f+1,l); }

        if(f<n){fun(n,v,i+1,t+'(',f+1,l);}
        if(f>l){fun(n,v,i+1,t+')',f,l+1);}

    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string t;
        int f=0;
        int l=0;

        fun(n,v,0,t,f,l);

        return v;
        
    }
};