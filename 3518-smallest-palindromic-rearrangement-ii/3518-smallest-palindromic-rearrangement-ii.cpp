class Solution {
public:

    long long nCr(int n,int r,int k){
        long long result=1;
        for(int i=1;i<=r;i++){
            result=result*(n-r+i)/i;
            if(result>=k)return k;
        }
        return result;
    }


    string smallestPalindrome(string s, int k) {
        vector<int> freq(26,0);
        int n=s.length();
        for(int i=0;i<n;i++)freq[s[i]-'a']++;

        string mid="";
        string half="";

        for(int i=0;i<26;i++){
            if(freq[i]%2==0){
                freq[i]/=2;
            }
            else{
                mid=i+'a';
                freq[i]/=2;
            }
        }

        for(int i=0;i<n/2;i++){
            bool isBuild=false;
            for(int j=0;j<26;j++){
                if(freq[j]>0){
                    freq[j]--;
                    long long ways=1;
                    int letters=n/2-i-1;
                    for(int c=0;c<26;c++){
                        if(freq[c]>0){
                            ways*=nCr(letters,freq[c],k);
                            letters-=freq[c];
                            if(ways>=k)break;
                        }
                    }
                    if(ways>=k){
                        half+=(j+'a');
                        isBuild=true;
                        break;
                    }
                    freq[j]++;
                    k-=ways;
                }
            }
            if(isBuild==false)return "";
        }

        string temp=half;
        reverse(temp.begin(),temp.end());
        return half+mid+temp;
    }
};