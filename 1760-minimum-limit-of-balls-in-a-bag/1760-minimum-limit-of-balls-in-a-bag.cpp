class Solution {
public:

    bool isPossible(vector<int>& nums,int maxOperations,int mid){
        long long totalOps=0;

        for(int i=0;i<nums.size();i++){
            totalOps+=(nums[i]-1LL)/mid;
            if(totalOps>maxOperations)return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1;
        int right=INT_MIN;

        for(int i=0;i<nums.size();i++)right=max(right,nums[i]);

        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isPossible(nums,maxOperations,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};