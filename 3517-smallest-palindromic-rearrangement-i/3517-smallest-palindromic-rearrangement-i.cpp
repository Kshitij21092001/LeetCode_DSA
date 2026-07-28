class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n<3)return s;
        vector<int> freq(26,0);
        string spec="";
        string ans="";
        
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq[i]==0)continue;
            if(freq[i]%2==0){
                ans.append(freq[i]/2, char(i+'a'));
            }
            else{
                if(freq[i]/2!=0)ans.append(freq[i]/2, char(i+'a'));
                spec=i+'a';
            }
        }

        sort(ans.begin(),ans.end());
        string temp=ans;
        reverse(temp.begin(),temp.end());

        return ans+spec+temp;
    }
};