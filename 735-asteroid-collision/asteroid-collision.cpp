class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n=asteroids.size();
        vector<int> v;

        int a,b;

        for(int i=0;i<n;i++){
            bool c=true;

                while(!s.empty() && s.top() > 0 && asteroids[i] < 0){
                    a=asteroids[i];
                    b=s.top();

                    if(abs(a)>abs(b)){
                        s.pop();
                    }
                    else if(abs(a)==abs(b)){
                        s.pop();
                        c=false;
                        break;
                    }
                    else{
                        c=false;
                        break;
                    }
                }

            if(c){
                s.push(asteroids[i]);
            }
        }   

        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }

        reverse(v.begin(),v.end());

        return v;
    }
};