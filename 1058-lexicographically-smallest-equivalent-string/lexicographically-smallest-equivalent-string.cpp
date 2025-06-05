class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        for (int i = 0; i < s1.length(); ++i)
            unite(s1[i] - 'a', s2[i] - 'a');

        string result;
        for (char c : baseStr) {
            int rep = find(c - 'a');
            result += (char)(rep + 'a');
        }
        return result;
    }
};
