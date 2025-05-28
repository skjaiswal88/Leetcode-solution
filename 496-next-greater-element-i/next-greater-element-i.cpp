class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> v(nums2.size(),-1);
        vector<int> an;

        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(nums2[i]);
            }
            else if(nums2[i]>=s.top()){
                while(!s.empty() && nums2[i]>=s.top()){s.pop();}

                if(!s.empty()){v[i]=s.top();}
                s.push(nums2[i]);
            }
            else{
                if(!s.empty()){v[i]=s.top();}
                s.push(nums2[i]);
            }
        }

        for(int j=0;j<nums1.size();j++){
            for(int k=0;k<nums2.size();k++){
                if(nums1[j]==nums2[k]){
                    an.push_back(v[k]);
                }
            }
        }
        return an;
    }
};