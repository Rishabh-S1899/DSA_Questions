#include<algorithm>
class Solution {
private: 
    bool unique(const vector<int>& subset, const vector<vector<int>>& ans) {
    unordered_set<int> s(subset.begin(), subset.end());
    if (s.size() != subset.size()) {
        return false;
    }

    auto it = std::find_if(ans.begin(), ans.end(), [&subset](const vector<int>& vec) {
        return vec.size() == subset.size() && is_permutation(vec.begin(), vec.end(), subset.begin(), subset.end());
    });

    return it == ans.end();
}
    
    bool issubset(vector<vector<int>> &ans,vector<int>& nums, vector<int> subset,int n ){
        if(subset.size()>n){
            return false;
        }
        if(!unique(subset,ans)){
            return false;
        }
        return true;
    }
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> subset, int n, int idx){
        // cout<<"This is subset size: "<<subset.size()<<endl;
        if((subset.size()==n)){
            // cout<<"return"<<endl;
            // ans.push_back(subset);
            return ;
        }
        for(int i=0; i<n; i++){
            // if(nums[i]<)
            subset.push_back(nums[i]);
            if(issubset(ans,nums, subset,n)){
                ans.push_back(subset);
                solve(nums, ans, subset, n ,i);
            }
            subset.pop_back();
        }
    } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> a={{}};
        if(nums.size()==0){
            return a;
        }
        vector<vector<int>> ans;
        vector<int> subset ;
        ans.push_back(subset);
        // cout<<"This is subset size: "<<subset.size();
        int n=nums.size();
        // cout<<"This is n: "<<n<<endl;
        solve(nums, ans,subset,n,0);
        return ans;

    }
};