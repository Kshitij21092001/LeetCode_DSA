class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int count=0;

        while(r<nums.size()-1){
            int farthestInd=0;
            for(int i=l;i<=r;i++)farthestInd=max(farthestInd,i+nums[i]);
            l=r+1;
            r=farthestInd;
            count++;
        }
        return count;
    }
};