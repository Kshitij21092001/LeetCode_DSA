class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int n=s.length();

        for(int i=0;i<n;i+=2){
            string temp=s.substr(i,2);
            int oneCnt=0;
            int zeroCnt=0;
            for(int j=0;j<2;j++){
                if(temp[j]=='1')oneCnt++;
                else zeroCnt++;
            }

            if(oneCnt==0 || zeroCnt==0)continue;
            ans++;
        }
        return ans;
    }
};