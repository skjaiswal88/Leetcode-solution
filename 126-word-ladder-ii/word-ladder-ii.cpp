#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> depthMap;
        vector<vector<string>> ans;
        
        // BFS to find the shortest path
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        depthMap[beginWord] = 1;
        wordSet.erase(beginWord);
        
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = depthMap[word];
            if (word == endWord) break;
            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (wordSet.count(word)) {
                        q.push(word);
                        wordSet.erase(word);
                        depthMap[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        
        // DFS to find all paths
        if (depthMap.count(endWord)) {
            vector<string> seq = {endWord};
            dfs(endWord, beginWord, seq, depthMap, ans);
        }
        
        return ans;
    }
    
private:
    void dfs(string word, string beginWord, vector<string>& seq, unordered_map<string, int>& depthMap, vector<vector<string>>& ans) {
        if (word == beginWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int steps = depthMap[word];
        for (int i = 0; i < word.size(); ++i) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (depthMap.count(word) && depthMap[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, beginWord, seq, depthMap, ans);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
};



// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         vector<vector<string>> result;
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         if (!dict.count(endWord)) return result;

//         queue<vector<string>> q;
//         q.push({beginWord});

//         unordered_set<string> visited;
//         bool found = false;

//         while (!q.empty() && !found) {
//             int size = q.size();
//             unordered_set<string> levelVisited;

//             for (int i = 0; i < size; i++) {
//                 vector<string> path = q.front(); q.pop();
//                 string word = path.back();

//                 for (int j = 0; j < word.size(); j++) {
//                     string temp = word;
//                     for (char c = 'a'; c <= 'z'; c++) {
//                         temp[j] = c;
//                         if (!dict.count(temp)) continue;

//                         vector<string> newPath = path;
//                         newPath.push_back(temp);

//                         if (temp == endWord) {
//                             found = true;
//                             result.push_back(newPath);
//                         } else {
//                             q.push(newPath);
//                         }

//                         levelVisited.insert(temp);
//                     }
//                 }
//             }

//             for (const string& w : levelVisited) dict.erase(w);
//         }

//         return result;
//     }
// };
