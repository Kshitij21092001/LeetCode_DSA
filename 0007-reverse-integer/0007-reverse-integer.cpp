class Solution {
public:
    int reverse(int x) {
        int temp=x;
        vector<int> v;

        long long ans=0;
        long long mul=1;
        while(temp){
            v.push_back(temp%10);
            temp/=10;
        }

        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i]*mul;
            mul*=10;
        }

        if (ans > INT_MAX || ans < INT_MIN) return 0;
        return (int)ans;
    }
};