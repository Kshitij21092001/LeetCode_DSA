class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();

        int i=0;
        int j=0;
        int result=INT_MAX;
        int minLen=INT_MAX;
        int currSum=0;
        vector<int> prevMinLen(n,INT_MAX);

        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>target)currSum-=arr[i++];

            if(currSum==target){
                int currLen=j-i+1;
                if(i>0 && prevMinLen[i-1]!=INT_MAX)result=min(result,currLen+prevMinLen[i-1]);
                minLen=min(minLen,currLen);

            }
            prevMinLen[j]=minLen;
            j++;
        }
        return result==INT_MAX?-1:result;
    }
};