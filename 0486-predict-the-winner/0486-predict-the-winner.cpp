class Solution {
public:

    int helper(int left,int right, vector<int>& nums, vector<vector<int>>& dp){
        if(left==right)return nums[left];
        if(dp[left][right]!=-1)return dp[left][right];

        return dp[left][right]=max(nums[left]-helper(left+1,right,nums,dp),nums[right]-helper(left,right-1,nums,dp));
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,n-1,nums,dp)>=0;
    }
};