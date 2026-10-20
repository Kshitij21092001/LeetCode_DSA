class Solution {
public:

    bool isSortable(vector<int>& nums,int i,int j, int& currMin,int& currMax){
        int count=0;
        int ind=-1;

        for(int k=i;k<=j-1;k++){
            if(nums[k]>nums[k+1]){
                count++;
                ind=k;
            }
        }
        if(nums[j]>nums[i])count++;
        if(count>1)return false;
        
        if(ind==-1){
            currMin=nums[i];
            currMax=nums[j];
        }
        else{
            currMin=nums[ind+1];
            currMax=nums[ind];
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        unordered_set<int> divisors;
        int n=nums.size();

        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divisors.insert(i);
                divisors.insert(n/i);
            }
        }

        int ans=0;
        for(auto div:divisors){
            bool flag=true;
            int prevMax=0;
            for(int i=0;i<n;i+=div){
                int j=i+div-1;
                int currMax;
                int currMin;
                if(!isSortable(nums,i,j,currMin,currMax)||currMin<prevMax){
                    flag=false;
                    break;
                }
                prevMax=currMax;
            }
            if(flag)ans+=div;
        }
        return ans;
    }
};