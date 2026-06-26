class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        //in these kind of questions, try to derive mathematical expressions for understanding
        //logic here is, cumSum[j]>cumSum[i-1] for that subarray having max freq after converting
        //to 1 and -1
        //for that we will keep a hashmap which will store the occurance of any freq, and add/remove accordingly

        int n=nums.size();
        unordered_map<int,int> mp; //after converting to 1 and -1, max size wille be 2*n+1
        mp[0]=1;
        long long validLeft=0;
        long long ans=0;
        int cumSum=0;

        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validLeft+=mp[cumSum];
                cumSum++;
            }
            else{
                cumSum--;
                validLeft-=mp[cumSum];
            }
            mp[cumSum]++;
            ans+=validLeft;
        }
        return ans;
    }
};