class Solution {
private:
    // void checker(vector<vector<int>>& heights , vector<vector<int>>track , unordered_map <string, bool> value )
    void resetVector(vector<vector<int>>& vec) {
    for (auto& row : vec) {
        fill(row.begin(), row.end(), 0);
    }
}
    void dfs(vector<vector<int>>& heights, vector<vector<int>> &track, int x , int y, unordered_map<char,bool> &value , int row, int col){
        // cout<<"DFS called for: "<<x<<" "<<y<<endl;
        vector<pair<int,int>> vec = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int n=vec.size();
        track[x][y]=1;
        for(int k=0; k<n ; k++){
            int i=x+vec[k].first;
            int j=y+vec[k].second;
            // cout<<"I and J are: "<<i<<" "<<j<<endl;
            if(i < 0 || j < 0 ){
            value['p']=true;
            // cout<<"Value for p marked true"<<endl;
            continue;
            }
            if(i >= row || j >= col){
            value['a']=true;
            // cout<<"value for a marked true"<<endl;
            continue;
            }
            else{
                if(heights[i][j] <= heights[x][y] && track[i][j]==0){
                // track[i][j]=1;
                dfs(heights,track,i,j,value,row,col);
                }
            }
            
        }    

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row= heights.size();
        int col= heights[0].size(); 
        vector<vector<int>> ans;
        vector<vector<int>> track (row, vector<int>(col,0));
        unordered_map <char, bool> value;
        value['p']=false;
        value['a']=false;
        for(int i=0; i<row; i++ ){
            for(int j=0 ; j<col ; j++){
                value['p']=false;
                value['a']=false;
                dfs(heights, track, i ,j, value, row , col);
                // cout<<"For i,j : "<<i<<" "<<j<<" Values of p and a are: "<<value['p']<<" "<<value['a']<<endl;
                if(value['p'] && value['a']){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                    temp.clear();
                }
                resetVector(track);
            }
        }
        return ans;
    }
};