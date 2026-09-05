class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxNum(n);
        vector<int> minNum(n);

        maxNum[0]=nums[0];
        minNum[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            maxNum[i]=max(maxNum[i-1],nums[i]);
            minNum[n-i-1]=min(minNum[n-i],nums[n-i-1]);
        }

        vector<int> instab(n);
        int minInst=INT_MAX;
        int ans=1e6;
        for(int i=0;i<n;i++){
            instab[i]=maxNum[i]-minNum[i];
            if(instab[i]<=k){
                ans=min(ans,i);
            }
        }
        if(ans==1e6)return -1;
        return ans;
    }
};