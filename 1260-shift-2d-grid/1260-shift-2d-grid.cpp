class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        k%=temp.size();
        int ind=(temp.size()-k)%temp.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=temp[ind];
                ind++;
                if(ind==temp.size())ind=0;
            }
        }
        return grid;
    }
};