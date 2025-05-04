#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    bool canAssign(int k, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());
        int usedPills = 0;

        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];
            auto it = available.lower_bound(task);
            if (it != available.end()) {
                available.erase(it);
            } else {
                if (++usedPills > pills) return false;
                it = available.lower_bound(task - strength);
                if (it == available.end()) return false;
                available.erase(it);
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = min(tasks.size(), workers.size()), answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};
