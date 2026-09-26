class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sourceSum=accumulate(source.begin(),source.end(),0LL);
        long long targetSum=accumulate(target.begin(),target.end(),0LL);

        return sourceSum==targetSum;
    }
};