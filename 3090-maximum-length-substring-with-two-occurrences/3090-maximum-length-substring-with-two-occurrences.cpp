class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen=INT_MIN;
        int n=s.length();
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(freq[s[j]-'a']<=2)maxLen=max(maxLen,(j-i+1));
                else break;
            }
        }
        return maxLen;
    }
};