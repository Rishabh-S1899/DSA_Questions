//My approach(Direct DFS implement for cycle detection in DAG)

class Solution {
private:
    bool dfs(vector<int>& visited, unordered_map<int,vector<int>>& adjlst, int node, vector<int> dfs_call){
        visited[node]=true;
        dfs_call[node]=true;
        for(auto i : adjlst[node]){
            if(!visited[i]){
                bool cycledetected =dfs(visited, adjlst, i , dfs_call);
                if(cycledetected){
                    return true;
                }
            }
            else if(dfs_call[i]){
                return true;
            }
        }
        dfs_call[node]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjlst;
        int n= prerequisites.size();
        for(int i=0 ; i<n ;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adjlst[u].push_back(v);
        }
        vector<int> visited(numCourses,false);
        vector<int> dfs_call(numCourses,false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool iscycle =dfs(visited, adjlst, i , dfs_call);
                if(iscycle){
                    return false;
                }
            }
        }
        return true;
    }
};

//Kahn's Algo based Approach(BFS For cycle detection in DAG)
// class Solution {
// public:
//     bool canFinish(int n, vector<vector<int>>& prerequisites) {
//         vector<int> adj[n];
//         vector<int> indegree(n, 0);
//         vector<int> ans;

//         for(auto x: prerequisites){
//             adj[x[0]].push_back(x[1]);
//             indegree[x[1]]++;
//         }

//         queue<int> q;
//         for(int i = 0; i < n; i++){
//             if(indegree[i] == 0){
//                 q.push(i);
//             }
//         }

//         while(!q.empty()){
//             auto t = q.front();
//             ans.push_back(t);
//             q.pop();

//             for(auto x: adj[t]){
//                 indegree[x]--;
//                 if(indegree[x] == 0){
//                     q.push(x);
//                 }
//             }
//         }
//         return ans.size() == n;
//     }
// };
