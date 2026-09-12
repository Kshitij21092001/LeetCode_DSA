class Solution {
public:

    int helper(int currNum,int total,int n,vector<vector<int>>& dp){
        if(total==n)return 1;
        if(total>n)return 1e7;

        if(dp[currNum][total]!=-1)return dp[currNum][total];
        
        int take=1+helper(currNum+1,total+currNum,n,dp);
        int skip=INT_MAX;
        if(currNum!=1)skip=1+helper(1,total,n,dp);

        return dp[currNum][total]=min(skip,take);
    }
    
    int minDays(int n) {
        int maxStreak=0;

        while((maxStreak+1)*(maxStreak+2)/2 <=n)maxStreak++;
        vector<vector<int>> dp(maxStreak+2,vector<int>(n+1,-1));
        return helper(1,0,n,dp)-1;
    }
};