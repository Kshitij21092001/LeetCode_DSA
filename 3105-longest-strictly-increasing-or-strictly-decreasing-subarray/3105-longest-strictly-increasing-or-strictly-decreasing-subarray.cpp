class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;

        int n=nums.size();

        for(int i=0;i<n;i++){
            int len=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]){
                    len++;
                }
                else{
                    inc=max(inc,len);
                    break;
                }
            }
            inc=max(inc,len);
        }

        for(int i=n-1;i>=0;i--){
            int len=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]>nums[j+1]){
                    len++;
                }
                else{
                    dec=max(dec,len);
                    break;
                }
            }
            dec=max(dec,len);
        }

        return max(inc,dec);
    }
};