class Disjoint {
    vector<int> pa, s;
public:
    Disjoint(int n) {
        pa.resize(n);
        s.resize(n, 1);
        for (int i = 0; i < n; i++) pa[i] = i;
    }

    int par(int a) {
        if (pa[a] == a) return a;
        return pa[a] = par(pa[a]);
    }

    bool uni(int a, int b) {
        int ua = par(a);
        int ub = par(b);
        if (ua == ub) return false;

        if (s[ua] > s[ub]) {
            pa[ub] = ua;
            s[ua] += s[ub];
        } else {
            pa[ua] = ub;
            s[ub] += s[ua];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjoint dsu(n);
        unordered_map<string,int> mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    dsu.uni(mp[mail],i);
                }
            }
        }

    vector<vector<string>> v(n);

    for(auto it:mp){
        string ma=it.first;
        int pa=dsu.par(it.second);
        v[pa].push_back(ma);
    }

    vector<vector<string>> an;

    for(int i=0;i<n;i++){
        if(v[i].empty()) continue;
        sort(v[i].begin(),v[i].end());
        vector<string> t;
        t.push_back(accounts[i][0]);

        for(auto y:v[i]){
        t.push_back(y);
        }
        an.push_back(t);
    }

    return an;
    }
};