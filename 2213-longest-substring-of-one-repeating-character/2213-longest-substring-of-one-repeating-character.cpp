class Solution {
public:

    struct Node{
        int pre=0;//repeating pref length
        int suf=0;
        int maxLen=0;//max repeating length
        char leftChar=0;
        char rightChar=0;
    };

    int n;
    vector<Node> segTree;//this will of of size 4*n

    Node merge(const Node& L,const Node& R, int leftLen,int rightLen){
        Node res;

        res.leftChar=L.leftChar;
        res.rightChar=R.rightChar;

        res.pre=L.pre;
        if(L.pre==leftLen && R.leftChar==L.rightChar){
            res.pre=leftLen+R.pre;
        }

        res.suf=R.suf;
        if(R.suf==rightLen && L.rightChar==R.leftChar){
            res.suf=rightLen+L.suf;
        }

        res.maxLen=max(L.maxLen,R.maxLen);
        if(L.rightChar==R.leftChar){
            res.maxLen=max(res.maxLen,(L.suf+R.pre));
        }

        return res;

    }

    void buildSegmentTree(int i,int l,int r,string& s){
        if(l==r){
            segTree[i]={1,1,1,s[l],s[l]};
            return;
        }

        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,s);
        buildSegmentTree(2*i+2,mid+1,r,s);
        segTree[i]=merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }

    void update(int i,int l,int r,int pos,char ch){
        if(l==r){
            segTree[i]={1,1,1,ch,ch};
            return;
        }

        int mid=l+(r-l)/2;
        if(pos<=mid)update(2*i+1,l,mid,pos,ch);
        else update(2*i+2,mid+1,r,pos,ch);

        segTree[i]=merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n=s.length();
        segTree.assign(4*n,Node());

        buildSegmentTree(0,0,n-1,s);

        int k=queryIndices.size();
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            int pos=queryIndices[i];
            char ch=queryCharacters[i];
            update(0,0,n-1,pos,ch);

            ans[i]=segTree[0].maxLen;
        }

        return ans;
    }
};