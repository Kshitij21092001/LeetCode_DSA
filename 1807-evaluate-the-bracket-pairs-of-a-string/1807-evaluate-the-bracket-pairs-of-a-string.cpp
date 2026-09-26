class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        string ans="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                string temp="";
                int ind=i+1;
                while(s[ind]!=')'){
                    temp+=s[ind];
                    ind++;
                }
                if(mp.count(temp)>0)ans+=mp[temp];
                else ans+="?";
                i=ind;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};