class Solution {
private:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& track, int x, int y, int row, int col){
        //UP
        if(x-1 >=0 && grid[x-1][y]=='1' && track[x-1][y]==0){
            track[x-1][y]=1;
            dfs(grid,track, x-1,y, row, col);
        }
        //Left
        if(y-1 >=0 && grid[x][y-1]=='1' && track[x][y-1]==0){
            track[x][y-1]=1;
            dfs(grid,track, x,y-1, row, col);
        }
        //Down
        if(x+1 < row  && grid[x+1][y]=='1' && track[x+1][y]==0){
            track[x+1][y]=1;
            dfs(grid,track,x+1,y, row, col);
        }
        //Right
        if(y+1 < col && grid[x][y+1]=='1' && track[x][y+1]==0){
            track[x][y+1]=1;
            dfs(grid,track,x,y+1, row, col);
        }
        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> track(row, vector<int>(col,0));
        int count=0;
        for(int i=0; i<row;i++){
            for(int j=0; j<col ;j++){
                if(grid[i][j]=='1' && track[i][j]==0){
                    track[i][j]=1;
                    dfs(grid, track , i, j, row, col);
                    count++;
                }
            }
        }
        return count;
    }
    
};

