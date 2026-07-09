class DSU{
    public:
    vector<int> size;
    vector<int> parent;

    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }

    int ultimateParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=ultimateParent(parent[u]);
    }

    void unionBySize(int u,int v){
        int uPar=ultimateParent(u);
        int vPar=ultimateParent(v);

        if(uPar==vPar)return;
        if(size[uPar]>size[vPar]){
            size[uPar]+=size[vPar];
            parent[vPar]=uPar;
        }
        else{
            size[vPar]+=size[uPar];
            parent[uPar]=vPar;
        }
        return;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsuObj(n);
        int i=0;
        int j=0;

        while(i<=j && j<n){
            if(abs(nums[i]-nums[j])<=maxDiff){
                dsuObj.unionBySize(i,j);
                j++;
            }
            else{
                i++;
            }
            if(i==j)j++;
        }

        vector<bool> ans;
        for(auto i:queries){
            int u=i[0];
            int v=i[1];

            if(dsuObj.ultimateParent(u)==dsuObj.ultimateParent(v))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};