class Solution {
public:
    void resetVector(vector<vector<int>>& vec) {
    for (auto& row : vec) {
        fill(row.begin(), row.end(), 0);
    }
}
    void dfs(vector<vector<char>>& ans,vector<vector<char>>& board , vector<vector<int>> &track , int row , int col , int x, int y, bool& reach){
        if(x-1<0 || x+1==row || y-1<0 || y+1==col){
            reach=true;
            board=ans;
            return ;
        }
        track[x][y]=1;
        board[x][y]='X';
        vector<pair<int,int>> vec = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int k=0; k<4 ;k++){
            int i=x+vec[k].first;
            int j=y+vec[k].second;
            if(board[i][j] != 'X' && track[i][j] == 0){
                dfs(ans,board, track, row, col, i , j , reach);
                if(reach){
                    break;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row= board.size();
        int col= board[0].size();
        vector<vector<int>> track(row,vector<int>(col,0));
        vector<vector<char>> ans(board);
        bool reach=false;
        for(int i=0; i<row ;i++){
            for(int j=0 ; j<col ;j++){
                if(board[i][j]=='O'){
                    reach=false;
                    dfs(ans,board, track , row, col, i , j , reach);
                    ans=board;
                    resetVector(track);
                }
            }
        }
    }
};
