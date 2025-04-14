typedef long long ll;

class Solution {
public:

    typedef long long ll;
    ll mod =1e9+7;

    ll res(ll ba, ll ex, ll mod){
        ll an=1;
        while(ex>0){
            if(ex%2==1){
                an=(an*ba)%mod;
            }
            ba=(ba*ba)%mod;
            ex=ex/2;
        }
            return an;
    }

    int countGoodNumbers(long long n) {
        ll ev=(n+1)/2;
        ll od=n/2;

        return (res(5,ev,mod) * res(4,od,mod))%mod;
    }
};



