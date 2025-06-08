class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Find max frequency
        int max_freq = *max_element(freq.begin(), freq.end());
        
        // Count how many tasks have max frequency
        int max_count = 0;
        for (int f : freq) {
            if (f == max_freq) {
                max_count++;
            }
        }
        
        // Calculate the minimum intervals required
        int part_count = max_freq - 1;
        int part_length = n - (max_count - 1);
        int empty_slots = part_count * part_length;
        int available_tasks = tasks.size() - max_freq * max_count;
        int idles = max(0, empty_slots - available_tasks);
        
        return tasks.size() + idles;
        
        // Alternatively, you can use the formula below:
        // return max((int)tasks.size(), (max_freq - 1) * (n + 1) + max_count);
    }
};
