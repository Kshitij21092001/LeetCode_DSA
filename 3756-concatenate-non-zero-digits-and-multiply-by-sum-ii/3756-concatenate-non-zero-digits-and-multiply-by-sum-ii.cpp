class Solution {
public:

    int mod=1e9+7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long currSum=0;
        int n=s.length();
        vector<long long> digitSum(n);
        for(int i=0;i<n;i++){
            currSum+=s[i]-'0';
            digitSum[i]=currSum;
        } 

        long long currNum=0;
        vector<long long> numberUpto(n);
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                numberUpto[i]=currNum;
                continue;
            }
            currNum=(currNum*10+(s[i]-'0'))%mod;
            numberUpto[i]=currNum;
        }

        int currNonZero=0;
        vector<int> nonZero(n);
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                nonZero[i]=currNonZero;
                continue;
            }
            currNonZero++;
            nonZero[i]=currNonZero;
        }

        vector<long long> pow10(n+1,0);
        pow10[0]=1;
        for(int i=1;i<=n;i++)pow10[i]=(pow10[i-1]*10)%mod;

        vector<int> ans;
        for(auto i:queries){
            long long sum;
            if(i[0]==0){
                sum=digitSum[i[1]];
            }
            else sum=digitSum[i[1]]-digitSum[i[0]-1];

            long long x;
            if(i[0]==0){
                x=numberUpto[i[1]];
            }
            else{
                long long k=nonZero[i[1]]-nonZero[i[0]-1];
                long long mul=pow10[k]%mod;
                x=((numberUpto[i[1]]-(numberUpto[i[0]-1]*mul)%mod)+mod)%mod;
            }
            ans.push_back(((x%mod)*(sum%mod))%mod);
        }
        return ans;
    }
};