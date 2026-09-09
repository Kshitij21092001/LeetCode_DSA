class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        else if(n>=1000 && n<=999999)return n-999;
        else if(n>=1000000 && n<=999999999)return 2*(n-999999)+999000;
        else if(n>=1000000000 && n<=999999999999)return 3*(n-999999999)+2*999000000+999000;
        else if(n>=1000000000000 && n<= 999999999999999)return 4*(n-999999999999)+3*999000000000+2*999000000+999000;
        return (long long)5*(n-999999999999999)+(long long)4*999000000000000+(long long)3*999000000000+(long long)2*999000000+999000;
    }
};