class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        if(n==0){
            vector<int> val;
            for(int i=0; i<numCourses ; i++){
                val.push_back(i);
            }
            return val;
        }
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;
        int count=0;
        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        for(int i=0 ;i<numCourses ;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // cout<<"This is the size of indegree "<<indegree.size()<<endl;
        // cout<<"This is "<<indegree[0]<<" "<<indegree[1]<<endl;
        while(!q.empty()){
            auto temp=q.front();
            cout<<"This is temp "<<temp<<endl;
            q.pop(); 
            count++;
            ans.push_back(temp);
            for(auto j : adj[temp] ){
                indegree[j]--;
                if(indegree[j]==0){
                    q.push(j);
            }
        }
       }
       if(count == numCourses) return ans; 
        
        return {}; 
    }
};