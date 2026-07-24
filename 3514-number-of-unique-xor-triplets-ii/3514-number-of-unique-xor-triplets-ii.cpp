class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int> first;
        int n=nums.size();
        if(n==1)return n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=nums[i]^nums[j];
                first[temp]++;
            }
        }

        unordered_map<int,int> second;
        for(int i=0;i<n;i++){
            for(auto it:first){
                int temp=nums[i]^it.first;
                second[temp]++;
            }
        }
        return second.size();
    }
};