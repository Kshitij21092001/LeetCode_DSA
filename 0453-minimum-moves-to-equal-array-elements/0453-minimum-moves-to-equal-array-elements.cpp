class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum=*min_element(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            ans+=(nums[i]-minNum);
        }
        return ans;
    }
};