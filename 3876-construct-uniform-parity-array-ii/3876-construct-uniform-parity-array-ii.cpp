class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minNum=*min_element(nums.begin(),nums.end());

        if(minNum%2==0){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==minNum)continue;
                if(nums[i]%2==1)return false;
            }
        }
        return true;
    }
};