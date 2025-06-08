class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task : tasks) {
            freq[task - 'A']++;
        }

        priority_queue<int> pq;
        for(int f : freq) {
            if(f > 0) pq.push(f);
        }

        int intervals = 0;
        int cycle = n + 1;

        while(!pq.empty()) {
            vector<int> temp;
            int count = 0;

            for(int i = 0; i < cycle; i++) {
                if(!pq.empty()) {
                    int top = pq.top();
                    pq.pop();
                    if(top > 1) temp.push_back(top - 1);
                    intervals++;
                    count++;
                } else {
                    // If no tasks left in this cycle break early if no tasks remain
                    if(temp.empty()) break;
                    intervals++;  // idle interval
                }
            }

            for(int t : temp) {
                pq.push(t);
            }
        }

        return intervals;
    }
};
