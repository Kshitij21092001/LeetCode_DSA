class Solution {
public:
    int mod=1e9+7;
    int helper(int n,int k,int ind,vector<vector<int>>& dp){
        if(k==0)return 1;
        if(ind>=n)return 0;
        if(dp[k][ind]!=-1)return dp[k][ind];
        int skip=helper(n,k,ind+1,dp);

        int take=0;
        for(int i=ind+1;i<n;i++){
            take=take+helper(n,k-1,i,dp);
        }
        return dp[k][ind]=skip+take;
    }

    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        //return helper(n,K,0,dp);

        for(int i=0;i<n;i++)dp[0][i]=1;

        for(int k=1;k<=K;k++){
            vector<int> prevSum(n+1,0);

            for(int x=n-1;x>=0;x--){
                prevSum[x]=(prevSum[x+1]+dp[k-1][x])%mod;
            }

            for(int i=n-1;i>=0;i--){
                long long take=0;
                take=prevSum[i+1];
                // for(int j=i+1;j<n;j++){
                //     take=(take+dp[k-1][j])%mod;
                // }
                long long skip=dp[k][i+1];
                dp[k][i]=(take+skip)%mod;
            }
        }
        return dp[K][0];
    }
};