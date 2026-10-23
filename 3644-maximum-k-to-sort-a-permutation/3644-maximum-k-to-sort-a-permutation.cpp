class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> swap;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                swap.push_back(nums[i]);
            }
        }

        if(swap.size()==0)return 0;

        int ans=swap[0];
        for(int i=1;i<swap.size();i++){
            ans=ans&swap[i];
        }
        return ans;
    }
};