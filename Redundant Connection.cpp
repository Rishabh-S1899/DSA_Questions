class Solution {
public:
    void makeset(vector<int>& parent, vector<int>& rank, int n){
        for(int i=1 ; i<n+1 ;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    void unionset(int u , int v, vector<int>& parent, vector<int>& rank){
        u=findparent(parent,u);
        v=findparent(parent,v);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        if(rank[v]>rank[u]){
            parent[u]=v;
        }
        if(rank[u]==rank[v]){
            parent[u]=v;
            rank[v]++;
        }
    }
    int findparent(vector<int>& parent , int node ){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findparent(parent, parent[node]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        vector<int> ans(2);
        makeset(parent, rank, n);
        for(int j=0 ; j< n; j++){
            if(findparent(parent,edges[j][0])==findparent(parent,edges[j][1])){
                ans[0]=edges[j][0];
                ans[1]=edges[j][1];
            }
            unionset(edges[j][0],edges[j][1],parent,rank);    
        }
        return ans;

    }
};
