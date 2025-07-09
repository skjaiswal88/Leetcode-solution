class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        if(!st.count(endWord)) return 0;
         unordered_set<string> vi;
        q.push({beginWord,1});
        vi.insert(beginWord);

        while(!q.empty()){
            auto [word, steps] =q.front(); q.pop();
            if(word==endWord) return steps;

            for(int i=0;i<word.size();i++){
                string o=word;
                for(char c='a'; c <='z'; c++){
                    o[i]=c;
                    if(st.count(o) && !vi.count(o)){
                        q.push({o,steps+1});
                        vi.insert(o);
                    }
                }
            }

        }
        return 0;
    }
};