class Solution {
public:

    int digitSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> pr;
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int sum=digitSum(nums[i]);
            pr.push_back({sum,nums[i]});
            mp[nums[i]]=i;
        }

        sort(pr.begin(),pr.end());
        int count=0;

        for(int i=0;i<n;i++){
            if(nums[i]!=pr[i].second){
                int currNum=nums[i];
                int currInd=mp[pr[i].second];
                swap(nums[i],nums[mp[pr[i].second]]);
                count++;
                mp[nums[i]]=i;
                mp[currNum]=currInd;
            }
        }            
        return count;
    }
};