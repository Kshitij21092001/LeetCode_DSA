class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<long long> powers;
        if(n<3)return n;
        for(int i=2;i<32;i++)powers.push_back(pow(2,i));
        return (int)*lower_bound(powers.begin(),powers.end(),n+1);
    }
};