class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto minIt=min_element(nums.begin(),nums.end());
        auto maxIt=max_element(nums.begin(),nums.end());

        int minIndex=distance(nums.begin(),minIt);
        int maxIndex=distance(nums.begin(),maxIt);

        int n=nums.size();
        // int minStep;
        // int minSide;
        // int maxStep;
        // int maxSide;
        // if(minIndex+1<n-minIndex){
        //     minStep=minIndex+1;
        //     minSide=0;
        // }
        // else{
        //     minStep=n-minIndex;
        //     minSide=1;
        // }

        // if(maxIndex+1<n-maxIndex){
        //     maxStep=maxIndex+1;
        //     maxSide=0;
        // }
        // else{
        //     maxStep=n-maxIndex;
        //     maxSide=1;
        // }

        // //if(minSide!=maxSide)return minStep+maxStep;
        // return min(minStep+maxStep,max(minStep,maxStep));

        int frontBack=minIndex+1+n-maxIndex;
        int backFront=n-minIndex+maxIndex+1;
        int frontFront=max(minIndex+1,maxIndex+1);
        int backBack=max(n-minIndex,n-maxIndex);

        return min(min(frontBack,backFront),min(frontFront,backBack));
    }
};