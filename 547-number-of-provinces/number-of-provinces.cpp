class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> v;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        queue<int> q;
        set<int> st;
        int an=0;
        
        for(int i=0;i<n;i++){  
            if(st.count(i)) continue;

            q.push(i);
        while(!q.empty()){
            int te=q.front();
            q.pop();

            if(!st.count(te)){
                st.insert(te);
                

                for(int f:adj[te]){
                    if(!st.count(f)){
                        q.push(f);
                    }
                    
                }
            }
        }
            an++;
        }

        return an;
    }
};