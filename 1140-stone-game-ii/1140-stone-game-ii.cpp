class Solution {
public:

    int helper(int ind,int m,vector<int>& piles,vector<vector<int>>& dp){
        if(ind>=piles.size())return 0;

        if(dp[ind][m]!=INT_MIN)return dp[ind][m];

        int ans=INT_MIN;
        int temp=0;
        for(int i=1;i<=2*m && i+ind<=piles.size();i++){
            int newM=max(m,i);
            temp+=piles[i+ind-1];
            ans=max(ans,temp-helper(i+ind,newM,piles,dp));
        }
        return dp[ind][m]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n+1,INT_MIN));
        int total=accumulate(piles.begin(),piles.end(),0);
        return (total+helper(0,1,piles,dp))/2;
    }
};