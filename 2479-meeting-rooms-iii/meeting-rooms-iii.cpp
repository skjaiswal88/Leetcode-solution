class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> avail;
        for (int i = 0; i < n; ++i)
            avail.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        vector<int> count(n, 0);

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];

            while (!busy.empty() && busy.top().first <= start) {
                avail.push(busy.top().second);
                busy.pop();
            }

            if (!avail.empty()) {
                int room = avail.top(); avail.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = busy.top(); busy.pop();
                long long duration = end - start;
                busy.push({freeTime + duration, room});
                count[room]++;
            }
        }

        int maxCount = 0, resRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                resRoom = i;
            }
        }

        return resRoom;
    }
};
