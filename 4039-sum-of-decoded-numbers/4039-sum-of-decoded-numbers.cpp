class Solution {
public:

    void findXY(long long& x,long long& y,long long& width, long long& d){
        vector<int> digits;

        while(d){
            digits.push_back(d%10);
            d/=10;
        }
        reverse(digits.begin(),digits.end());

        x=0;
        int i=0;
        while(i<width){
            x=(x*10)+digits[i];
            i++;
        }

        y=0;
        while(i<digits.size()){
            y=(y*10)+digits[i];
            i++;
        }
        return;
    }

    long long modPow(long long x,long long y, long long mod){
        long long result=1;
        x%=mod;
        while(y){
            if(y&1)result=(result*x)%mod;
            x=(x*x)%mod;
            y/=2;
        }
        return result;
    }
    
    int sumDecoded(vector<long long>& nums) {
        long long mod=1e9+7;
        long long ans=0;

        for(int i=0;i<nums.size();i++){
            long long width=nums[i]%10;
            long long d=floor(nums[i]/10);
            
            long long x,y;
            findXY(x,y,width,d);
            ans=(ans+modPow(x,y,mod))%mod;
            ans%=mod;
        }
        return (int)ans;
    }
};