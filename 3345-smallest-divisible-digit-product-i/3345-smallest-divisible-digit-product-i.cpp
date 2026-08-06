class Solution {
public:

    int product(int n){
        int ans=1;
        while(n){
            ans*=(n%10);
            n/=10;
        }
        return ans;
    }

    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int prd=product(i);
            if(prd%t==0)return i;
        }
        return 100;
    }
};