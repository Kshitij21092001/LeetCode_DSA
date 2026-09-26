class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int sum=0;
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                //(sum-2x)%k ->sum%k==2x%k
                int xMod=((2*nums[j])%k +k)%k;
                st.insert(xMod);
                
                if(sum%k==0)ans=max(ans,j-i+1);
                else{
                    int required=((sum%k)+k)%k;
                    if(st.count(required)){
                        ans=max(ans,j-i+1);
                    }
                }
            }
            
        }
        return ans;
    }
};