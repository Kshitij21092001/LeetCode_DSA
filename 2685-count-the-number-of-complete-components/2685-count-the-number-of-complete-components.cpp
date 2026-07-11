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
        int pU=ultimateParent(u);
        int pV=ultimateParent(v);

        if(pU==pV)return;
        if(size[pU]>size[pV]){
            parent[pV]=pU;
            size[pU]+=size[pV];
        }
        else{
            parent[pU]=pV;
            size[pV]+=size[pU];
        }
        return;
    }
};

class Solution {
public:

    int countCompleteComponents(int n, vector<vector<int>>& edges) {   
        DSU dsuObj(n);

        for(auto it:edges){
            dsuObj.unionBySize(it[0],it[1]);
        }

        unordered_map<int,int> mp;
        unordered_map<int,int> edgeCount;

        for(auto it:edges){
            int parent=dsuObj.ultimateParent(it[0]);
            edgeCount[parent]++;
        }

        for(int i=0;i<n;i++){
            mp[dsuObj.ultimateParent(i)]++;
        }

        int count=0;
        for(auto it:mp){
            int parent=it.first;
            int vertices=dsuObj.size[parent];
            int edges=edgeCount[parent];

            if(edges==(vertices*(vertices-1))/2)count++;
        }
        return count;
    }
};