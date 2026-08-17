class Solution {
public:
    int totalSum=0;
    int helper(int left,int right,vector<int>& preSum, vector<vector<int>>& dp){
        if(left==right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];

        int ans=0;
        for(int k=left;k<right;k++){
            int leftSum=preSum[k]-(left>0?preSum[left-1]:0);
            int rightSum=preSum[right]-preSum[k];

            if(leftSum>rightSum)ans=max(ans,rightSum+helper(k+1,right,preSum,dp));
            else if(leftSum<rightSum)ans=max(ans,leftSum+helper(left,k,preSum,dp));
            else ans=max(ans,max(rightSum+helper(k+1,right,preSum,dp),leftSum+helper(left,k,preSum,dp)));
        }
        return dp[left][right]=ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        vector<int> preSum;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=stoneValue[i];
            preSum.push_back(currSum);
        }
        totalSum=currSum;
        return helper(0,n-1,preSum,dp);
    }
};