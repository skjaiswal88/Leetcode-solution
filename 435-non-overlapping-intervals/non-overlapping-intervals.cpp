class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;      // Count of non-overlapping intervals
        int end = INT_MIN;  // Track the end of the last selected interval

        for (const auto& interval : intervals) {
            if (interval[0] >= end) {
                // No overlap, select this interval
                count++;
                end = interval[1];
            }
        }

        // Total intervals - non-overlapping intervals = minimum to remove
        return intervals.size() - count;
    }
};
