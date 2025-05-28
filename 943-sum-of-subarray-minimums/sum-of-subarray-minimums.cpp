class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int an=0;
        int mod=(int)1e9+7;

        vector<int> nse(n,n);
        vector<int> pse(n,-1);

        stack<int> s;
        stack<int> p;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
            if(!s.empty()) nse[i]=s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++){
            while(!p.empty() && arr[p.top()]>=arr[i]) p.pop();
            if(!p.empty()) pse[i]=p.top();
            p.push(i);
        }

        for(int j=0;j<n;j++){
            an=(an+((j-pse[j])*(nse[j]-j)*1LL)%mod*arr[j])%mod;
        }

        return an;
    }
};