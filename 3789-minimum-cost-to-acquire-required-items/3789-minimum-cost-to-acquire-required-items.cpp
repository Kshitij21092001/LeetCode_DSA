class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2<=costBoth){
            return (long long)(1LL*cost1*need1 + 1LL*cost2*need2);
        }

        long long ans=0;
        long long minNeed=min(need1,need2);
        ans+=1LL*costBoth*minNeed;

        need1-=minNeed;
        need2-=minNeed;

        if(need1!=0){
            ans+=(1LL*need1*(min(cost1,costBoth)));
        }
        if(need2!=0){
            ans+=(1LL*need2*(min(cost2,costBoth)));
        }

        return ans;
    }
};