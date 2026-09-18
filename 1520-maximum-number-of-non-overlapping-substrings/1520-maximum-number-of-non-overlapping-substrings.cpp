class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> startInd(26,-1);
        vector<int> endInd(26,-1);
        vector<bool> isValid(26,true);//to check is it possible to form substring from this char

        vector<string> ans;
        int currentStringLastInd=INT_MAX;

        for(int i=0;i<s.length();i++){
            if(startInd[s[i]-'a']==-1)startInd[s[i]-'a']=i;
            endInd[s[i]-'a']=i;
        }

        for(int i=0;i<26;i++){
            if(startInd[i]==-1)continue;

            for(int innerInd=startInd[i];innerInd<=endInd[i];innerInd++){
                if(startInd[s[innerInd]-'a']<startInd[i]){
                    isValid[i]=false;
                    break;
                }

                endInd[i]=max(endInd[i],endInd[s[innerInd]-'a']);
            }
        }

        for(int i=s.length()-1;i>=0;i--){
            int c=s[i]-'a';

            if(!isValid[c])continue;

            if(i==startInd[c] && endInd[c]<currentStringLastInd){
                ans.push_back(s.substr(startInd[c],endInd[c]-startInd[c]+1));
                currentStringLastInd=i;
            }
        }
        return ans;
    }
};