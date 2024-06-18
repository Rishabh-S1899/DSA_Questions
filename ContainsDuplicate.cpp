class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // set<int> s(nums.begin(),nums.end());
        // return s.size() != nums.size() ? true : false ;
        unordered_map<int,bool> visited;
        int n= nums.size();
        for(int i=0 ;i< n ;i++){
            if(visited[nums[i]]==true){
                return true;
            }
            else{
                visited[nums[i]]=true;
            }
        }
        return false;
    }   
};