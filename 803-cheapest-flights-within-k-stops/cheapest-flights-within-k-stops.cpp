class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<int> v(n,INT_MAX);

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});

        while(!pq.empty()){
            auto[co,po,s]=pq.top(); pq.pop();
            if(po==dst) return co;

            if(s<=k && s<v[po]){
                v[po]=s;

                for(auto p:adj[po]){
                    int ne=p.first;
                    int c=p.second;

                    pq.push({co+c,ne,s+1});
                }
            }

        }
        return -1;
    }
};