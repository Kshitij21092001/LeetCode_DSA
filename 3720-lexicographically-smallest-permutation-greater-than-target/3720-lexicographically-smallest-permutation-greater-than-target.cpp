class Solution {
public:
    string result="";

    bool helper(string& curr,vector<int>& freq,int ind,string& s, string& target,bool greater){
        if(ind==s.length()){
            if(greater){
                result=curr;
                return true;
            }
            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(freq[ch-'a']==0)continue;

            if(greater==false && ch<target[ind])continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool isGreater=greater||ch>target[ind];

            if(helper(curr,freq,ind+1,s,target,isGreater))return true;

            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26,0);

        for(int i=0;i<s.length();i++)freq[s[i]-'a']++;
        string curr="";
        helper(curr,freq,0,s,target,false);

        return result;
    }
};