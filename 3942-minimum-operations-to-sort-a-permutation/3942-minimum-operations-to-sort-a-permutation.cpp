class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int incCount=0;
        int decCount=0;

        for(int i=1;i<n;i++){
            if(nums[i]==(nums[i-1]+1)%n)incCount++;
            if(nums[i-1]==(nums[i]+1)%n)decCount++;
        }

        if(incCount==n-1 && nums[0]==0)return 0;

        if(incCount==n-1){
            int leftRot=n-nums[0];
            int rightRot=1+(nums[n-1]+1)+1;
            return min(leftRot,rightRot);
        }
        if(decCount==n-1){
            int leftRot=n-nums[n-1]+1;
            int rightRot=(nums[0]+1)%n +1;
            return min(leftRot,rightRot);
        }
        return -1;
    }
};