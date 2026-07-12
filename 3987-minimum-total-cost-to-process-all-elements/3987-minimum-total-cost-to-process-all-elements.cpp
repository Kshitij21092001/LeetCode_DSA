class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long originalK=k;
        long long currCost=1;
        long long totalCost=0;
        int mod=1e9+7;
        
        for(int i=0;i<nums.size();i++){
            if(k>=nums[i]){
                k-=nums[i];
                continue;
            }
            else{
                long long ops=((nums[i]-k)+originalK-1)/originalK;
                __int128 sum=(__int128)ops*(2LL*currCost+ops-1);
                sum/=2;
                totalCost=(totalCost+(long long)(sum%mod)%mod);
                currCost+=ops;
                k+=(ops*originalK);
                k-=nums[i];
            }
        }
        return totalCost%mod;
    }
};