class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int firstCase=abs(nums[1]-nums[n-2]);
        int secondCase=abs(nums[n-3]-nums[0]);
        int thirdCase=abs(nums[n-1]-nums[2]);

        return min(firstCase,min(secondCase,thirdCase));
    }
};