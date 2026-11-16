class Solution {
public:

    string helper(string& s,int k,int i){
        if(i>=s.length())return "";

        int currLen=s.length()-i;
        int len=min(k,currLen);
        string temp=s.substr(i,len);

        int sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=(temp[i]-'0');
        }
        temp=to_string(sum);

        return temp+helper(s,k,i+k);
    }

    string digitSum(string s, int k) {
        string ans=s;

        while(ans.length()>k){
            ans=helper(ans,k,0);
        }

        return ans;
    }
};