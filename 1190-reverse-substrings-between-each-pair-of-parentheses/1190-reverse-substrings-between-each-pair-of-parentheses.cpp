class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push("");
            }
            else if(s[i]==')'){
                string top=st.top();
                st.pop();
                reverse(top.begin(),top.end());
                st.top()+=top;
            }
            else{
                st.top()+=s[i];
            }
        }
        return st.top();
    }
};