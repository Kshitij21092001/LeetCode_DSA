class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        int minNum=INT_MAX;
        int maxNum=INT_MIN;

        for(int i=0;i<n;i++){
            minNum=min(minNum,nums[i]);
            maxNum=max(maxNum,nums[i]);
            mp[nums[i]]++;
        }

        for(int i=minNum;i<=maxNum;i++){
            if(mp.count(i)==0)ans.push_back(i);
        }

        return ans;
    }
};