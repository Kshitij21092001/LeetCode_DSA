class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        int mod=1e9+7;
        vector<vector<int>> up(n+1,vector<int>(m,0));
        vector<vector<int>> down(n+1,vector<int>(m,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)continue;
                if(i<j)up[2][j]=(up[2][j]+1)%mod;
                else down[2][j]=(down[2][j]+1)%mod;
            }
        }

        for(int i=3;i<=n;i++){
            vector<int> prefUp(m+1,0);
            vector<int> prefDown(m+1,0);

            for(int v=0;v<m;v++){
                prefUp[v+1]=(prefUp[v]+up[i-1][v])%mod;
                prefDown[v+1]=(prefDown[v]+down[i-1][v])%mod;
            }

            for(int y=0;y<m;y++){
                up[i][y]=prefDown[y]%mod;
                down[i][y]=((prefUp[m]-prefUp[y+1])%mod+mod)%mod;
            }
        }

        long long ans=0;
        if(n==1)return m;
        else{
            for(int y=0;y<m;y++){
                ans=(ans+up[n][y]+down[n][y])%mod;
            }
        }
        return ans;
    }
};