class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(maxEle-nums[i]);
        }

        return ans;
    }
};