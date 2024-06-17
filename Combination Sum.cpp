class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> candidates, vector<int> &track, int idx, int t, int target,int currsum){
        //Base Case
        if(currsum==target){
            ans.push_back(track);
            return ;
        }
        if(currsum>target || idx==t ){
            return ;
        }
        track.push_back(candidates[idx]);
        currsum+=candidates[idx];
        solve(ans,candidates,track,idx,t, target,currsum);
        track.pop_back();
        currsum-=candidates[idx];
        solve(ans,candidates,track,idx+1,t, target,currsum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> track;
        int t=candidates.size();
        int curr_sum=0;
        solve(ans,candidates,track, 0 , t, target, curr_sum);
        return ans;
    }
};