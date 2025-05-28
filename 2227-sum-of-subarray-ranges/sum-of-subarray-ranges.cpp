class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long an=0;
        long long v=0;

        vector<int> nse(n,n);
        vector<int> pse(n,-1);

        vector<int> nge(n,n);
        vector<int> pge(n,-1);

        stack<int> s;
        stack<int> p;

        stack<int> a;
        stack<int> b;

        for(int i=n-1;i>=0;i--){
            while(!a.empty() && nums[a.top()]<nums[i]) a.pop();
            if(!a.empty()) nge[i]=a.top();
            a.push(i);
        }

        for(int i=0;i<n;i++){
            while(!b.empty() && nums[b.top()]<=nums[i]) b.pop();
            if(!b.empty()) pge[i]=b.top();
            b.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>nums[i]) s.pop();
            if(!s.empty()) nse[i]=s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++){
            while(!p.empty() && nums[p.top()]>=nums[i]) p.pop();
            if(!p.empty()) pse[i]=p.top();
            p.push(i);
        }

        for(int j=0;j<n;j++){
            an=an+((j-pse[j])*(nse[j]-j)*1LL)*nums[j]; 
            v=v+((j-pge[j])*(nge[j]-j)*1LL)*nums[j];
        }

        return v-an;

    }
};