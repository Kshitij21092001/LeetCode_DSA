class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count=0;

        int i=0;
        int j=0;
        int n=nums.size();
        unordered_map<int,int> blocks;

        
        while(j<n){
            i=j;
            while(j<n && nums[i]==nums[j])j++;

            blocks[nums[i]]++;
        }

        for(auto itr:blocks){
            if(itr.second==1)count++;
        }
        return count;
    }
};