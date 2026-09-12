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
            if(it.second.size()>=3){
                bool flag=true;
                int diff=temp[1]-temp[0];
                for(int i=2;i<temp.size();i++){
                    if(temp[i]-temp[i-1]!=diff)flag=false;
                }
                if(flag)ans++;
            }
        }
        return ans;
    }
};