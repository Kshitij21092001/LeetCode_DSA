class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> ideal;
        int count=0;
        ideal['a']=1;
        ideal['b']=1;
        ideal['c']=1;

        int n=s.length();
        int i=0;
        int j=0;
        unordered_map<char,int> curr;
        while(i<=j && j<n){
            curr[s[j]]++;
            if(curr.size()==ideal.size())count+=(n-j);

            while(curr.size()==ideal.size()){
                curr[s[i]]--;
                if(curr[s[i]]==0)curr.erase(s[i]);
                if(curr.size()==ideal.size())count+=(n-j);
                i++;
            }
            j++;
        }
        return count;
    }
};