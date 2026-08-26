class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> v;
        int n=s.length();
        int minLen=n;

        for(int i=0;i<n;i++){
            int oneCount=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1')oneCount++;
                if(oneCount==k){
                    v.push_back(s.substr(i,(j-i+1)));
                    minLen=min(minLen,j-i+1);
                }
                if(oneCount>k)break;
            }
        }

        vector<string> ans;
        for(int i=0;i<v.size();i++){
            if(v[i].length()==minLen)ans.push_back(v[i]);
        }

        sort(ans.begin(),ans.end());
        if(ans.size()!=0)return ans[0];
        return "";
    }
};