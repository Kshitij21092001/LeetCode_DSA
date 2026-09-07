class Solution {
public:
    
    void helper(int ind,unordered_map<string,int>& mp,string s,string& curr){
        if(ind==s.length()){
            if(!curr.empty())mp[curr]++;
            return;
        }

        helper(ind+1,mp,s,curr);
        curr+=s[ind];
        helper(ind+1,mp,s,curr);
        curr.pop_back();
        return;
    }

    int distinctSubseqII(string s) {
        //unordered_map<string,int> mp;
        //string curr="";
        //helper(0,mp,s,curr);
        //return mp.size();
        int mod=1e9+7;
        int n=s.length();
        vector<long long> dp(n+1);
        dp[0]=1;
        unordered_map<char,int> mp;

        for(int i=0;i<n;i++){
            dp[i+1]=(2LL*(dp[i]))%mod;
            if(mp.count(s[i])!=0){
                dp[i+1]=((dp[i+1]-dp[mp[s[i]]])%mod+mod)%mod;
            }
            mp[s[i]]=i;
        }
        return (int)(dp[n]-1+mod)%mod;
    }
};