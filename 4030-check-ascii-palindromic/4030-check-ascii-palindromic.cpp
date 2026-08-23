class Solution {
public:

    bool palindrome(string s){
        int i=0;
        int j=s.length()-1;

        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindromic(string s) {
        string ans="";

        for(int i=0;i<s.length();i++){
            int num=s[i];
            ans+=(bitset<8>(num).to_string());
        }

        return palindrome(ans);
    }
};