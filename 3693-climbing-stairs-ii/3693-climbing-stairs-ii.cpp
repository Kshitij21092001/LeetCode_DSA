class Solution {
public:

    int helper(int i,vector<int>& costs,vector<int>& dp){
        int n=costs.size();
        if(i==n)return 0;
        if(i>n)return 1e7;

        if(dp[i]!=-1)return dp[i];

        int first,second,third;
        if(i+1<=n)first=costs[i]+1+helper(i+1,costs,dp);
        else first=1e7;
        if(i+2<=n)second=costs[i+1]+4+helper(i+2,costs,dp);
        else second=1e7;
        if(i+3<=n)third=costs[i+2]+9+helper(i+3,costs,dp);
        else third=1e7;

        return dp[i]=min(first,min(second,third));
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return helper(0,costs,dp);
    }
};