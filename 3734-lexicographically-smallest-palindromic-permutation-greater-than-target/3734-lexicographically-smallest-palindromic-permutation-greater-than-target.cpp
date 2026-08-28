class Solution {
public:
    string ans="";
    string midChar="";

    bool helper(string& curr,int ind,vector<int>& freq,string& s,string& target,bool greater){
        if(curr.length()==s.length()/2){
            string left=curr;
            string right=curr;
            reverse(right.begin(),right.end());

            string final=left+midChar+right;
            if(final>target){
                ans=final;
                return true;
            }
            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(freq[ch-'a']==0)continue;
            if(greater==false && ch<target[ind])continue;

            curr+=ch;
            freq[ch-'a']--;

            bool isGreater=greater || ch>target[ind];
            if(helper(curr,ind+1,freq,s,target,isGreater))return true;
            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++)freq[s[i]-'a']++;

        int oddNum=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                oddNum++;
                midChar=i+'a';
            }
        }

        if(oddNum>1)return "";

        for(int i=0;i<26;i++)freq[i]/=2;

        string curr="";
        helper(curr,0,freq,s,target,false);
        return ans;
    }
};