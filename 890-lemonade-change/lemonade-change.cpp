class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0,b=0;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) {a++;}
            else if(bills[i]==10){
                if(a>0){
                    b++;
                    a--;
                }
                else {return false;}
            }
            else{
                if((b>0 && a>0)){
                    b--;  a--;
                }
                else if(a>=3){
                    a=a-3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
        
    }
};