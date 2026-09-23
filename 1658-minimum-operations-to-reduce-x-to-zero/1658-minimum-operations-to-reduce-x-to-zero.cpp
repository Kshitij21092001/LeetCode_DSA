class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        int i=0;
        int j=0;
        long long currSum=0;
        int reqSum=total-x;
        if(reqSum<0)return -1;
        if(reqSum==0)return n;

        while(i<=j && j<n){
            currSum+=nums[j];

            while(i<=j && currSum>reqSum){
                currSum-=nums[i];
                i++;
            }    

            if(currSum==reqSum){
                ans=max(ans,j-i+1);
            }
            j++;
        }

        return ans==0?-1:n-ans;

    }
};