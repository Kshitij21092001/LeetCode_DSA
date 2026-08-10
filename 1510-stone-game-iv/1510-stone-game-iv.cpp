class Solution {
public:

    bool helper(int n, vector<int>& dp){
        if(n==0)return false; //whoever reaches here, loses
        if(dp[n]!=-1)return dp[n];

        for(int i=1;i<=sqrt(n);i++){
            if(helper(n-(i*i),dp)==false){//means moving ahead, with all possible chances, bob loses
                return dp[n]=true;//so if bob loses, Alice wins definitely
            }
        }

        return dp[n]=false;//if alice never win from the inner loop, how can she win now
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        //return helper(n,dp);//true means alice wins

        for(int ind=0;ind<=n;ind++){
            for(int i=1;i<=sqrt(ind);i++){
                if(dp[ind-(i*i)]==0){
                    dp[ind]=1;
                    break;
                }
            }
        }

        return dp[n];
    }
};