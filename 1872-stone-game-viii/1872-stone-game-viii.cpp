class Solution {
public:
    int n;
    int helper(int ind,vector<int>& stones,vector<int>& dp){
        if(ind==n-1)return stones[n-1];
        if(dp[ind]!=-1)return dp[ind];

        int take=stones[ind]-helper(ind+1,stones,dp);
        int skip=helper(ind+1,stones,dp);
        return dp[ind]=max(take,skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        //vector<int> dp(n+1,-1);
        vector<int> dp(n,0);
        for(int i=1;i<n;i++)stones[i]+=stones[i-1];
        //return helper(1,stones,dp);
        dp[n-1]=stones[n-1];
        for(int i=n-2;i>=1;i--){
            int take=stones[i]-dp[i+1];
            int skip=dp[i+1];
            dp[i]=max(take,skip);
        }
        return dp[1];
    }
};