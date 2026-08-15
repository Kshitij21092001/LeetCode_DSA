class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool allZero=true;
        int xorAll=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)allZero=false;
            xorAll=xorAll^nums[i];
        }

        if(xorAll==0){
            if(allZero==true)return 0;
            return nums.size()-1;
        }
        return nums.size();
    }
};