class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0;
        int j=0;

        int ans=1;

        while(i<=j && j<nums.size()){
            if(mp[nums[j]]<=k-1){
                mp[nums[j]]++;
                j++;
            }
            else{
                ans=max(ans,(j-i));
                mp[nums[i]]--;
                i++;
            }
        }
        ans=max(ans,(j-i));
        return ans;
    }
};