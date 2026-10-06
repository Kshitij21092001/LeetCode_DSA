class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int n=s.length();
        int neg=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(')count++;
            else{
                count--;
                if(count<0){
                    neg++;
                    count=0;
                }
            }
        }
        return neg+count;
    }
};