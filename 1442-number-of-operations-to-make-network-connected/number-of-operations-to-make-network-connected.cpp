class Disjoint{
    vector<int> pa,s;
    public:
    Disjoint(int n){
        pa.resize(n+1);
        s.resize(n+1);
        for(int i=0;i<n;i++){
            pa[i]=i;
            s[1]=1;
        }
    }

    int par(int a){
        if(pa[a]==a) return a;
        return pa[a]=par(pa[a]);
    }

    void uni(int a,int b){
        int ua=par(a);
        int ub=par(b);

        if(ua==ub) return ;
        if(s[ua]>s[ub]){
            pa[ub]=ua;
            s[ua]=s[ua]+s[ub];
        }
        else{
            pa[ua]=ub;
            s[ub]=s[ub]+s[ua];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int f=connections.size();

        if(n-1>f) return -1;
        
        Disjoint dsu(n);
        set<int> st;

        for(auto e:connections){
            dsu.uni(e[0],e[1]);
        }

        for(int i=0;i<n;i++){
            st.insert(dsu.par(i));
        }

        return st.size()-1;

    }
};