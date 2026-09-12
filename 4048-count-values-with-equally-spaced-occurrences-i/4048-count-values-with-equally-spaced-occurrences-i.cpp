class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        int ans=0;
        for(auto it:mp){
            vector<int> temp=it.second;
            if(it.second.size()==3){
                if(abs(temp[1]-temp[0])==abs(temp[2]-temp[1]))ans++;
            }
        }
        return ans;
    }
};