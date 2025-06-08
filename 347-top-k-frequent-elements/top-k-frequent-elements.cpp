class compare{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first > b.first ;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(int i:nums){
            mp[i]++;
        }

        for(auto [nums,count]:mp){
            if(pq.size()<k){
                pq.push({count,nums});
            }
            else{
                if(pq.top().first<count){
                    pq.pop();
                    pq.push({count,nums});
                }
            }
        }

        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }

        return v;

    }
};