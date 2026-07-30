class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int ans=0;
        int mul=1;
        while(n){
            if(n>=8){
                ans+=(mul*8);
                n-=8;
            }
            else{
                ans=ans+(mul*n);
                n=0;
            }
            mul++;
        }

        return ans;
    }
};