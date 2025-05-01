class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& track, int x, int y, int row, int col, int &areacount){
        //UP
        if(x-1 >=0 && grid[x-1][y]==1 && track[x-1][y]==0){
            track[x-1][y]=1;
            areacount++;
            dfs(grid,track, x-1,y, row, col, areacount);
            
        }
        //Left
        if(y-1 >=0 && grid[x][y-1]==1 && track[x][y-1]==0){
            // cout<<"Condition 2"<<endl;
            track[x][y-1]=1;
            areacount++;
            dfs(grid,track, x,y-1, row, col, areacount);
            
        }
        //Down
        if(x+1 < row  && grid[x+1][y]==1 && track[x+1][y]==0){
            track[x+1][y]=1;
            areacount++;
            dfs(grid,track,x+1,y, row, col, areacount);
            
        }
        //Right
        if(y+1 < col && grid[x][y+1]==1 && track[x][y+1]==0){
            track[x][y+1]=1;
            areacount++;
            dfs(grid,track,x,y+1, row, col, areacount);
            
        }
        return ;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> track(row, vector<int>(col,0));
        int max_area=0;
        int areacount;
        for(int i=0; i<row;i++){
            for(int j=0; j<col ;j++){
                if(grid[i][j]==1 && track[i][j]==0){
                    areacount=0;
                    track[i][j]=1;
                    areacount++;
                    dfs(grid, track , i, j, row, col, areacount);
                    // count++;
                }
                max_area=max(max_area, areacount);
            }
        }
        return max_area;
    }
};