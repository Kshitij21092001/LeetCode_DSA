class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> countDiff(1e5+1,0);

        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            countDiff[diff]++;
        }

        int total=k1+k2;
        for(int i=1e5;i>0 && total>0;i--){
            int ops=min(total,countDiff[i]);

            countDiff[i]-=ops;
            countDiff[i-1]+=ops;
            total-=ops;
        }

        long long ans=0;
        for(long long i=0;i<=1e5;i++){
            ans+=(countDiff[i]*i*i);
        }
        return ans;
    }
};