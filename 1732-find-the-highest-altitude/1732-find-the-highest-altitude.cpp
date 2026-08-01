class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cumSum=0;
        int ans=INT_MIN;
        int n=gain.size();
        for(int i=0;i<n;i++){
            cumSum+=gain[i];
            ans=max(ans,cumSum);
        }
        if(ans<0)return 0;
        return ans;
    }
};