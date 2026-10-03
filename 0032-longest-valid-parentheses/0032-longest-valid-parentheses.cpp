class Solution {
public:
    int longestValidParentheses(string s) {
        //track the indices from where invalid pair formation starts
        stack<int> st;
        st.push(-1);
        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty())st.push(i);
                else{
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};