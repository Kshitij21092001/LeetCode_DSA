class Solution {
public:
    long long sumAndMultiply(int n) {
        long long digitSum=0;
        string num="";

        while(n){
            long long temp=n%10;
            if(temp!=0){
                num+='0'+temp;
            }
            digitSum+=temp;
            n/=10;
        }

        if(num.empty())return 0;
        reverse(num.begin(),num.end());
        return stoi(num)*digitSum;
    }
};