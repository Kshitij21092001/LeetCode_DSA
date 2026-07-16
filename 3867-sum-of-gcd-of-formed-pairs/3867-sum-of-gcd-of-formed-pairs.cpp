class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd(n);
        int maxVal=INT_MIN;
        for(int i=0;i<n;i++){
            maxVal=max(maxVal,nums[i]);
            prefixGcd[i]=__gcd(nums[i],maxVal);
        }

        long long sum=0;
        int i=0;
        int j=n-1;
        sort(prefixGcd.begin(),prefixGcd.end());
        while(i<j){
            int currGcd=__gcd(prefixGcd[i],prefixGcd[j]);
            sum+=(long long)currGcd;
            i++;
            j--;
        }
        return sum;
    }
};