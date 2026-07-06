class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        int lSum=0;
        int rSum=0;

        for(int i=0;i<n;i++){
            leftSum[i]=lSum;
            rightSum[n-i-1]=rSum;
            lSum+=nums[i];
            rSum+=nums[n-i-1];
        }
        
        for(int i=0;i<n;i++){
            nums[i]=abs(leftSum[i]-rightSum[i]);
        }
        return nums;
    }
};