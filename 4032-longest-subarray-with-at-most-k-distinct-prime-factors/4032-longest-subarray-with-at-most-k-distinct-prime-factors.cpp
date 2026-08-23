class Solution {
public:

    vector<int> pf(int n){
        vector<int> ans;

        if(n%2==0){
            ans.push_back(2);
            while(n%2==0)n/=2;
        }
        
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0)n/=i;
            }
        }

        if(n>2){
            ans.push_back(n);
        }
        return ans;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        vector<vector<int>> primes;
        int n=nums.size();

        for(int i=0;i<n;i++){
            primes.push_back(pf(nums[i]));
        }

        int i=0;
        int j=0;

        unordered_map<int,int> mp;
        int ans=0;
        while(i<=j && j<n){
            vector<int> prime=primes[j];
            for(int ind=0;ind<prime.size();ind++){
                mp[prime[ind]]++;
            }

            if(mp.size()<=k)ans=max(ans,(j-i+1));
            else{
                vector<int> prime2=primes[i];
                for(int ind=0;ind<prime2.size();ind++){
                    mp[prime2[ind]]--;
                    if(mp[prime2[ind]]==0)mp.erase(prime2[ind]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};