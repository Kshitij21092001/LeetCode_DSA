class Solution {
public:

    bool isValid(int num,unordered_map<int,int> mp){
        vector<int> digits;

        while(num){
            digits.push_back(num%10);
            num/=10;
        }

        for(int i=0;i<digits.size();i++){
            if(mp.count(digits[i])==0)return false;
            mp[digits[i]]--;
            if(mp[digits[i]]==0)mp.erase(digits[i]);
        }
        return true;
    }

    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;

        for(int i=0;i<digits.size();i++)mp[digits[i]]++;

        int ans=0;
        for(int i=100;i<=998;i++){
            if(i%2==0 && isValid(i,mp))ans++;
        }

        return ans;
    }
};