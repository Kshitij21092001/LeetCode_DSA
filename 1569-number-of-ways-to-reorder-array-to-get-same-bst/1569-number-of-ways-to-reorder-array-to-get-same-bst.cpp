class Solution {
public:
    int mod=1e9+7;
    vector<vector<long long>> pascalTriangle;

    int helper(vector<int>& nums){
        if(nums.size()<3)return 1;

        vector<int> left,right;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[0])left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long x=helper(left)%mod;
        long long y=helper(right)%mod;
        long long z=pascalTriangle[nums.size()-1][left.size()]%mod;

        return (((x*y)%mod)*z)%mod;
    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pascalTriangle.resize(n+1);

        for(int i=0;i<=n;i++){
            pascalTriangle[i]=vector<long long>(i+1,1);
            for(int j=1;j<i;j++){
                pascalTriangle[i][j]=(pascalTriangle[i-1][j]+pascalTriangle[i-1][j-1])%mod;
            }
        }

        return helper(nums)-1;
    }
};