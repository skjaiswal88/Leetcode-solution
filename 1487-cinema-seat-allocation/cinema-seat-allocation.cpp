class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> mp;
        int an=0;

        for(auto r:reservedSeats){
            int a=r[0]; 
            int b=r[1];
            

            if(b>=2 && b<=9){
                mp[a]=mp[a] | (1<<(b-2));
            }
        }

            for(auto [r,m]:mp){
                bool x = (0b00001111 & m) == 0;
                bool y = (0b11110000 & m) == 0;
                bool z = (0b00111100 & m) == 0;

                if(x && y) an=an+2;
                else if(x || y || z) an=an+1;
            }

            an=an+(n-mp.size())*2;


        

        return an;
    }
};