class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int startRow;
        int startCol;
        vector<pair<int,int>> litter;
        int m=classroom.size();
        int n=classroom[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    startRow=i;
                    startCol=j;
                }
                if(classroom[i][j]=='L')litter.push_back({i,j});
            }
        }

        int expectedMask=(1<<litter.size())-1;
        if(expectedMask==0)return 0;
        
        //q with row, col, currEnergy, currMask, currSteps
        queue<tuple<int,int,int,int,int>> q;
        //visited with energy value at row,col,mask
        vector<vector<vector<int>>> visited(m,vector<vector<int>> (n,vector<int> (expectedMask,-1)));

        q.push({startRow,startCol,energy,0,0});
        visited[startRow][startCol][0]=energy;

        int dRow[]={1,0,-1,0};
        int dCol[]={0,1,0,-1};

        while(!q.empty()){
            auto [currRow,currCol,currEnergy,currMask,currSteps]=q.front();
            q.pop();

            //because if this condition is not there, we will be adding energy from R to negetive values
            if(currEnergy==0)continue;

            for(int i=0;i<4;i++){
                int newRow=currRow+dRow[i];
                int newCol=currCol+dCol[i];

                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && classroom[newRow][newCol]!='X'){
                    int newEnergy=currEnergy-1;
                    int newMask=currMask;
                    if(classroom[newRow][newCol]=='R')newEnergy=energy;
                    if(classroom[newRow][newCol]=='L'){
                        //checking which bit to set from our total expectedMask
                        for(int i=0;i<litter.size();i++){
                            if(newRow==litter[i].first && newCol==litter[i].second){
                                newMask |= (1<<i);
                                break;
                            }
                        }
                    }

                    if(newMask==expectedMask)return currSteps+1;

                    //try to use combinations with higher energy to increase chances to collect all litter
                    if(visited[newRow][newCol][newMask]<newEnergy){
                        visited[newRow][newCol][newMask]=newEnergy;
                        q.push({newRow,newCol,newEnergy,newMask,currSteps+1});
                    }
                }
            }
        }

        return -1;
    }
};