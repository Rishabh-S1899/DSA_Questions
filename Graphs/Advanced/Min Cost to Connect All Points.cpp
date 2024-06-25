class Solution {
private:
    int findparent(vector<int>& parent, int node){
        if(parent[node]==-1){
            return node;
        }
        return parent[node]=findparent(parent,parent[node]);
    }
    void unionset(vector<int>& parent , vector<int>& rank , int u, int v){
        int u_p=findparent(parent,u);
        int v_p=findparent(parent,v);

        if(rank[u_p]>rank[v_p]){
            parent[v_p]=u_p;
        }
        if(rank[u_p]<rank[v_p]){
            parent[u_p]=v_p;
        }
        else{
            parent[v_p]=u_p;
            rank[u_p]++;
        }
    }
    
public:
    static bool myComparison(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b){
       return a.second<b.second;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<vector<int>,int> pointmap;
        for(int i=0 ; i<points.size() ; i++){
            pointmap.insert({points[i],i});
        }
        vector<pair<pair<int,int>,int>> adj;
        int n=points.size();
        //Makset work
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        for(int i=0 ; i<points.size();i++){
            for(int j=i ; j<points.size() ; j++){
                int dist=abs(points[i][0]-points[j][0]) +abs(points[i][1]-points[j][1]);
                adj.push_back(make_pair(make_pair(pointmap[points[i]],pointmap[points[j]]),dist));
            } 
        }
        sort(adj.begin(),adj.end(),myComparison);
        int cost=0;
        for(auto x: adj){
            if(findparent(parent,x.first.first)!=findparent(parent,x.first.second)){
                unionset(parent,rank,x.first.first,x.first.second);
                cost+=x.second;
            }
        }
        return cost;
    }
};
