class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for(auto e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<> >pq;
        vector<long long> v(n,LLONG_MAX);
        vector<int> w(n,0);
        v[0]=0;
        w[0]=1;

        pq.push({0,0});

        while(!pq.empty()){
            auto[di,nod]=pq.top(); pq.pop();

            if (di > v[nod]) continue;

            for(auto[ne,wt]: adj[nod]){
                if(di+wt<v[ne]){
                    v[ne]=di+wt;
                    w[ne]=w[nod];
                    pq.push({v[ne],ne});
                }
                else if(di+wt==v[ne]){
                    w[ne]=(w[ne]+w[nod])% MOD;
                }
            }
        }

        return w[n-1];

    }
};