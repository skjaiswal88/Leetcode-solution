class StockSpanner {
public:

    stack<pair<int,int>> s;

    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int,int> p={price,1};
        
        while(!s.empty() && p.first>=s.top().first){   
            p.second=p.second+s.top().second;
            s.pop();
        }

        s.push(p);

        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */