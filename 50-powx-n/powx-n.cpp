class Solution {
public:

    double fun(double x,long long n){
        if(n==0){return 1.0;}
        if(n==1){return x;}

        double as=fun(x,n/2);

        if(n%2==1){
            as=as*as*x;
        }
        else{
            as=as*as;
        }

        return as;
    }


    double myPow(double x, int n) {
        if(x==0.0){return 0.0;}
        if(x==1.0){return 1.0;}

        long long ne=n;

        if(ne<0){
            x=1/x;
            ne=-ne;
        }

        double an=fun(x,ne);

        return an;
        
    }
};