class Solution {
public:
    int maxCandies(vector<int>& status, 
                   vector<int>& candies, 
                   vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> haveBox(n, false), openable(n, false), opened(n, false);
        queue<int> q;
        int total = 0;
        
        // Initialize which boxes are initially openable
        for (int i = 0; i < n; ++i) {
            openable[i] = (status[i] == 1);
        }
        
        // Collect initial boxes
        for (int b : initialBoxes) {
            if (!haveBox[b]) {
                haveBox[b] = true;
                if (openable[b]) {
                    q.push(b);
                }
            }
        }
        
        // Process all boxes we can open
        while (!q.empty()) {
            int b = q.front();
            q.pop();
            if (opened[b]) continue;
            opened[b] = true;
            
            // Take candies from box b
            total += candies[b];
            
            // Use any keys found in box b
            for (int k : keys[b]) {
                if (!openable[k]) {
                    openable[k] = true;
                    if (haveBox[k] && !opened[k]) {
                        q.push(k);
                    }
                }
            }
            
            // Add any contained boxes to our possession
            for (int c : containedBoxes[b]) {
                if (!haveBox[c]) {
                    haveBox[c] = true;
                    if (openable[c] && !opened[c]) {
                        q.push(c);
                    }
                }
            }
        }
        
        return total;
    }
};
