class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0)return 0;
        if(s>n*9)return -1;
        int count=0;

        int ans=0;
        while(s>0 || count!=n){
            int digit=min(9,s);
            count++;
            ans=ans*10+digit;
            s-=digit;
        }
        return ans;
    }
};