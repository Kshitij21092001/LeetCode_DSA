class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }

        sort(nums.begin(),nums.end());

        long long x=0;
        long long y=0;
        int i=0;

        while(i<n/2){
            y+=nums[i]*nums[i];
            x+=nums[n-1-i]*nums[n-1-i];
            i++;
        }

        if(n%2==1)x+=nums[i]*nums[i];

        return x-y;
    }
};