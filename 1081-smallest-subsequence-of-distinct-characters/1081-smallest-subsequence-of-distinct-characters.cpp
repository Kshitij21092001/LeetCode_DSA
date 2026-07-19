class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastInd(26);
        vector<int> seen(26,0);
        stack<int> st;

        int n=s.length();
        for(int i=0;i<n;i++){
            lastInd[s[i]-'a']=i;
        }

        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']==1)continue;

            while(!st.empty() && s[st.top()]>s[i] && lastInd[s[st.top()]-'a']>i){
                seen[s[st.top()]-'a']=0;
                st.pop();
            } 
            st.push(i);
            seen[s[i]-'a']=1;
        }

        string ans="";
        while(!st.empty()){
            ans+=s[st.top()];
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};