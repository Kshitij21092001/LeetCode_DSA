class Solution {
public:

    int numProd(int n){
        int ans=1;

        while(n){
            ans*=(n%10);
            n/=10;
        }
        return ans;
    }

    int numSum(int n){
        int ans=0;

        while(n){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }

    bool checkDivisibility(int n) {
        int sum=numSum(n);
        int prod=numProd(n);

        return n%(sum+prod)==0;
    }
};