class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n=nums.size();
        int ans=-1;
        int maxElement=*max_element(nums.begin(),nums.end());
        if(k==n)return maxElement;
        
        vector<int> freq(51,0);
        for(int i=0;i<n;i++)freq[nums[i]]++;

        if(k==1){
            for(int i=0;i<51;i++){
                if(freq[i]==1)ans=max(ans,i);
            }
            return ans;
        }
        ans=-1;
        freq.assign(51,0);
        for(int i=0;i<=n-k;i++){

            for(int j=0;j<k;j++){
                freq[nums[i+j]]++;
            }
        }
        for(int i=0;i<51;i++){
            if(freq[i]==1)ans=max(ans,i);
        }
        return ans;

    }
};