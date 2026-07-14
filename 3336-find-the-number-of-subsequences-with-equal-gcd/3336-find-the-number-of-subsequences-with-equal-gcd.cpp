class Solution {
public:

    int mod=1e9+7;
    // int dp[201][201][201];
    // int solve(vector<int>& nums,int ind,int gcd1,int gcd2){
    //     if(ind==nums.size()){
    //         if(gcd1!=0 && gcd2!=0){
    //             if(gcd1==gcd2)return 1;
    //         }
    //         return 0;
    //     }

    //     if(dp[ind][gcd1][gcd2]!=-1)return dp[ind][gcd1][gcd2];

    //     int skip=solve(nums,ind+1,gcd1,gcd2);
    //     int take1=solve(nums,ind+1,__gcd(nums[ind],gcd1),gcd2);
    //     int take2=solve(nums,ind+1,gcd1,__gcd(nums[ind],gcd2));

    //     return dp[ind][gcd1][gcd2]=(0LL+skip+take1+take2)%mod;
    // }

    int subsequencePairCount(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        // return solve(nums,0,0,0);

        int n=nums.size();
        int maxEl=-1;
        for(int i=0;i<n;i++)maxEl=max(maxEl,nums[i]);

        int dp[n+1][maxEl+1][maxEl+1];

        for(int i=0;i<=maxEl;i++){
            for(int j=0;j<=maxEl;j++){
                if(i!=0 && j!=0){
                    if(i==j)dp[n][i][j]=1;
                    else dp[n][i][j]=0;
                }
                else dp[n][i][j]=0;
            }
        }

        for(int ind=n-1;ind>=0;ind--){
            for(int gcd1=maxEl;gcd1>=0;gcd1--){
                for(int gcd2=maxEl;gcd2>=0;gcd2--){
                    int skip=dp[ind+1][gcd1][gcd2];
                    int take1=dp[ind+1][__gcd(nums[ind],gcd1)][gcd2];
                    int take2=dp[ind+1][gcd1][__gcd(nums[ind],gcd2)];
                    dp[ind][gcd1][gcd2]=(0LL+skip+take1+take2)%mod;
                }
            }
        }        
        return dp[0][0][0];
    }
};