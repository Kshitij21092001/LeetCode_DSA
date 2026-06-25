class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        //int targetCount=0;
        for(int i=0;i<nums.size();i++){
            int targetCount=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target)targetCount++;
                if(2*targetCount>(j-i+1))ans++;
            }
        }
        return ans;
    }
};