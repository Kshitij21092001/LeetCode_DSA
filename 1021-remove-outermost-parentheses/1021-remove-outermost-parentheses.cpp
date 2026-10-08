class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        int j=0;
        string ans="";
        int count=0;

        while(i<=j && j<s.length()){
            if(s[j]=='(')count++;
            else count--;

            if(count==0){
                string temp=s.substr(i,j-i+1);
                string temp2=temp.substr(1,temp.length()-2);
                ans+=temp2;
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};