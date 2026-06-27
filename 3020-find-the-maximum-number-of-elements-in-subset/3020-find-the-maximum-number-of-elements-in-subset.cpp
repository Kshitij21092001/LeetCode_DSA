class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)mp[nums[i]]++;
        int ans=1;

        if(mp.count(1)){
            int countOne=mp[1];
            if(countOne%2==0)countOne--;
            ans=max(ans,countOne);
        }

        for(auto& it:mp){
            long long curr=it.first;
            int len=0;
            if(curr==1)continue;

            while(1){
                if(mp.count(curr)==0)break;
                if(mp[curr]==1){
                    len++;
                    break;
                }
                len+=2;

                if(curr>1000000000LL/curr)break;
                
                curr*=curr;
            }
            if(len%2==0)len--;
            ans=max(ans,len);
        }
        return ans;
    }
};