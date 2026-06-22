class DSU{
    public:
    vector<int> size;
    vector<int> parent;

    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
    }

    int findUltPar(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUltPar(parent[u]);
    }

    void unionBySize(int u,int v){
        int uPar=findUltPar(u);
        int vPar=findUltPar(v);

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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU obj(n);
        unordered_map<int,int> x_Cord;
        unordered_map<int,int> y_Cord;

        for(int i=0;i<n;i++){
            int x=stones[i][0];
            int y=stones[i][1];

            if(x_Cord.count(x)>0){
                if(obj.findUltPar(i)!=obj.findUltPar(x_Cord[x])){
                    obj.unionBySize(x_Cord[x],i);
                }
            }
            if(y_Cord.count(y)>0){
                if(obj.findUltPar(i)!=obj.findUltPar(y_Cord[y])){
                    obj.unionBySize(y_Cord[y],i);
                }
            }

            x_Cord[x]=i;
            y_Cord[y]=i;
        }

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int par=obj.findUltPar(i);
            mp[par]++;
        }
        return n-mp.size();
    }
};