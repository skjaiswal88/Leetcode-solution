class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        std::vector<int> index(n);
        for (int i = 0; i < n; i++){
            index[i] = i;
        }
        std::sort(index.begin(), index.end(), [&positions](int a, int b){
            return positions[a] < positions[b];
        });
        std::vector<int> stack;
        for (int i : index){
            if (directions[i] == 'R'){
                stack.push_back(i);
                continue;
            }
            while (!stack.empty() && healths[i] > 0){
                if (healths[stack.back()] < healths[i]){
                    healths[stack.back()] = 0;
                    stack.pop_back();
                    healths[i] -= 1;
                } else if (healths[stack.back()] > healths[i]) {
                    healths[stack.back()] -= 1;
                    healths[i] = 0;
                } else {
                    healths[stack.back()] = 0;
                    healths[i] = 0;
                    stack.pop_back();
                }
            }
        }
        std::vector<int> result;
        for (int h : healths) {
            if (h > 0) {
                result.push_back(h);
            }
        }

        return result;
    }
};