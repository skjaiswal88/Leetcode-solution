class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:times){
            adj[e[0]-1].push_back({e[1]-1,e[2]});
        }

        vector<int> v(n,INT_MAX);
        v[k-1]=0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<> >pq;

        pq.push({0,k-1});

        while(!pq.empty()){
            auto[di,nod]=pq.top(); pq.pop();

            for(auto[ne,wt]:adj[nod]){
                if(wt+di<v[ne]){
                    v[ne]=wt+di;
                    pq.push({v[ne],ne});
                }
            }

        }

        int an=INT_MIN;
        for(auto i:v){
            if(i==INT_MAX) return -1;
            else{
                an=max(an,i);
            }
        }
        return an;

    }
};